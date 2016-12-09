#include "Model.h"

Model::Model()
{

}

bool Model::blockIsSupported(const std::string &type)
{
    return blockProperties_.find(type) != blockProperties_.end();
}

bool Model::initialize(const std::vector<Block *> &blocks, const std::vector<Connector *> &connectors)
{
    for(Block* block: blocks)
        if(!blockIsSupported(block->type))
            return false;

    for(Block* block: blocks)
        block->setProperties(blockProperties_[block->type]);

    for(Connector* connector: connectors)
        connector->setProperties(connectorProperties_);

    return true;
}

void Model::addBlockProperty(const std::string &type, const Property &property)
{
    blockProperties_[type].push_back(property);
}

void Model::addConnectorProperty(const Property &property)
{
    connectorProperties_.push_back(property);
}

void Model::addNodeProperty(const Property &property)
{
    nodeProperties_.push_back(property);
}
