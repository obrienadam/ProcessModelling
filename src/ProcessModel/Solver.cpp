#include "Solver.h"

Solver::Solver()
{

}

bool Solver::solve(ProcessModel &pm)
{

}

void Solver::constructMaps(ProcessModel& pm)
{
    int id = 0;

    for(Block* block: pm.blocks())
        for(Node* node: *block)
        {
            indexToNodeMap_.push_back(node);
            nodeToIndexMap_[node] = id++;
        }
}
