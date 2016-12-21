#include <QDebug>
#include "Solver.h"

Solver::Solver()
{

}

bool Solver::solve(std::vector<Block*> &blocks,
                   std::vector<Connector*> &connectors,
                   bool useCachedMaps,
                   int maxIters)
{
    if(!useCachedMaps)
        constructMaps(blocks, connectors);

    for(int i = 0; i < maxIters; ++i)
    {
        matrix = Matrix(nodeToIndexMap_.size(), nodeToIndexMap_.size());
        b = Matrix(nodeToIndexMap_.size(), 1);

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
        Matrix x = arma::solve(matrix, b);

        mapSolutionToModel(x);
        updateFlowRates(connectors);
    }
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

void Solver::updateFlowRates(std::vector<Connector *> &connectors)
{
    for(Connector* connector: connectors)
    {
        double r = connector->getResistance();
        double p1 = connector->sourceNode()->getSolutionVariable("Pressure");
        double p2 = connector->destNode()->getSolutionVariable("Pressure");

        connector->setSolutionVariable("Flow rate", (p1 - p2)/r);
    }
}
