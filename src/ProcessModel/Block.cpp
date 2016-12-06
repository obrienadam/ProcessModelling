#include "Block.h"

Block::Block(int nInputs, int nOutputs, int nSinks, const std::string &type, const std::string &name)
    :
      type(type),
      name(name)
{
    for(int i = 0; i < nInputs; ++i)
    {
        inputs_.push_back(std::make_shared<Node>(Node::INPUT, this));
        nodes_.push_back(inputs_.back());
    }

    for(int i = 0; i < nOutputs; ++i)
    {
        outputs_.push_back(std::make_shared<Node>(Node::OUTPUT, this));
        nodes_.push_back(outputs_.back());
    }

    for(int i = 0; i < nSinks; ++i)
    {
        sinks_.push_back(std::make_shared<Node>(Node::SINK, this));
        nodes_.push_back(sinks_.back());
    }
}

Block::~Block()
{
    for(auto &node: nodes_)
        node->removeBlock();
}

void Block::addProperty(const std::string &name, double value, double min, double max)
{
    properties_.push_back(
                Property(name, value, min, max)
                );
}

void Block::setProperties(const std::vector<Property> &properties)
{
    properties_ = properties;
}
