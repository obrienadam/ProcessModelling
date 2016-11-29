#include <algorithm>

#include "processmodel.h"

ProcessModel::ProcessModel()
{

}

ProcessModel::~ProcessModel()
{
    for(Block* block: blocks_)
        delete block;
}

bool ProcessModel::addNodeProperty(const std::string &property)
{

}

void ProcessModel::addBlock(Block *block)
{
    blocks_.push_back(block);
}
