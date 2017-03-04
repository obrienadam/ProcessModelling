#include <QDebug>
#include "Solver.h"

Solver::Solver()
{

}

double Solver::solve(std::vector<Block*> &blocks,
                     std::vector<Connector*> &connectors,
                     bool useCachedMaps,
                     int maxIters)
{
    if(!useCachedMaps)
        constructMaps(blocks, connectors);

    for(Connector* conn: connectors)
        conn->setSolutionVariable("Flow rate", 0.);

    Matrix matrix(nodes().size(), nodes().size());
    Matrix x(nodes().size(), 1), xOld(nodes().size(), 1), b(nodes().size(), 1);

    for(int i = 0; i < maxIters; ++i)
    {
        matrix.fill(0.);
        b.fill(0.);

        //- Construct equations for block outputs/sinks
        for(Block* block: blocks)
        {
            block->setNodeEquations();

            for(const auto& node: block->nodes())
            {
                int row = nodeToIndexMap_[node.get()];

                for(const auto& entry: node->equation().coeffs())
                {
                    int col = nodeToIndexMap_[entry.first];

                    matrix(row, col) += entry.second;

                }

                b(row, 0) = node->equation().source();
            }
        }

        //- Solve
        xOld = x;
        x = arma::solve(matrix, b);

        mapSolutionToModel(x);
        double error = updateFlowRates(connectors);
        updateBlockSolutions(blocks);

        if(error < 1e-12)
            return error;
    }

    return -1;
}

void Solver::constructMaps(std::vector<Block *> &blocks, std::vector<Connector *> &connectors)
{
    int nodeIndex = 0;
    nodeToIndexMap_.clear();
    indexToNodeMap_.clear();

    //- Blocks take ownership for all nodes
    for(Block* block: blocks)
    {
        for(auto& node: block->nodes())
        {
            indexToNodeMap_.push_back(node.get());
            nodeToIndexMap_[node.get()] = nodeIndex++;
        }
    }

    if(indexToNodeMap_.size() != nodeToIndexMap_.size())
        throw std::exception();
}

void Solver::constructMatrix()
{

}

void Solver::mapSolutionToModel(const Matrix &x)
{
    for(int i = 0; i < nodes().size(); ++i)
        indexToNodeMap_[i]->setSolutionVariable("Pressure", x(i, 0));
}

void Solver::updateBlockSolutions(std::vector<Block *> &blocks)
{
    for(Block* block: blocks)
        block->updateSolution();
}

double Solver::updateFlowRates(std::vector<Connector *> &connectors)
{
    double errorNorm = 0.;

    for(Connector* connector: connectors)
    {
        double r = connector->getResistance();
        double p1 = connector->sourceNode()->getSolutionVariable("Pressure");
        double p2 = connector->destNode()->getSolutionVariable("Pressure");
        double Qold = connector->getSolutionVariable("Flow rate");
        double Q = ((p1 - p2)/r + Qold)/2.;

        connector->setSolutionVariable("Flow rate", Q);
        errorNorm = std::max(errorNorm, fabs((Q - Qold)/Qold));
    }

    return errorNorm;
}
