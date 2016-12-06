#include "Model.h"

Model::Model()
{

}

bool Model::blockIsSupported(const std::string &type)
{
    return blockProperties_.find(type) != blockProperties_.end();
}

void Model::initialize(const std::vector<Block *> &blocks, const std::vector<Connector *> &connectors)
{
    for(Block* block: blocks)
        if(blockIsSupported(block->type))
        {
            std::vector<Property> properties = blockProperties_[block->type];
            block->setProperties(properties);
        }
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
