#include <QDebug>
#include "Solver.h"

Solver::Solver()
{

}

bool Solver::solve(std::vector<Block*> &blocks, std::vector<Connector*> &connectors, bool useCachedMaps)
{
    if(!useCachedMaps)
        constructMaps(blocks, connectors);

    //- Construct equations for block outputs/sinks
    for(Block* block: blocks)
    {
        for(const auto& node: block->outputs())
        {
            for(const auto& entry: node->equation().coeffs())
            {
                matrix.add(
                            nodeToIndexMap_[node.get()],
                        nodeToIndexMap_[entry.first],
                        entry.second
                        );
            }

            //matrix.rhs.add(nodeToIndexMap_[node], node->equation().source());
        }

        for(const auto& sinks: block->sinks())
        {

        }
    }

    //- Construct equations for connector nodes
}

void Solver::constructMaps(std::vector<Block *> &blocks, std::vector<Connector *> &connectors)
{
    int nodeIndex = 0;
    nodeToIndexMap_.clear();
    indexToNodeMap_.clear();

    //- Blocks take ownership of outputs and sinks
    for(Block* block: blocks)
    {
        for(auto& node: block->outputs())
        {
            indexToNodeMap_.push_back(node.get());
            nodeToIndexMap_[node.get()] = nodeIndex++;
        }

        for(auto& node: block->sinks())
        {
            indexToNodeMap_.push_back(node.get());
            nodeToIndexMap_[node.get()] = nodeIndex++;
        }
    }

    //- Connectors take ownership of inputs only
    for(Connector* connector: connectors)
    {
        Node* node = connector->destNode();
        if(!node->isInput())
            continue;

        indexToNodeMap_.push_back(node);
        nodeToIndexMap_[node] = nodeIndex++;
    }

    if(indexToNodeMap_.size() != nodeToIndexMap_.size())
        throw std::exception();

    qDebug() << "Finished construction index maps, no errors detected."
             << "Nodes in solution =" << indexToNodeMap_.size();
}

void Solver::constructMatrix()
{

}

void Solver::mapSolutionToModel()
{

}
