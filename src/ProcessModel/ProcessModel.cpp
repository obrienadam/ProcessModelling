#include <algorithm>

#include "ProcessModel.h"

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
    return false;
}

void ProcessModel::addBlock(Block *block)
{
    blocks_.push_back(block);
}

void ProcessModel::deleteBlock(Block *block)
{
    blocks_.erase(std::find(blocks_.begin(), blocks_.end(), block));
    delete block;
}
