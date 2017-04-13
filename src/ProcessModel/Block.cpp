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

void Block::addProperty(const Property &property)
{
    properties_[property.symbol] = property;
}

void Block::setProperties(const std::map<std::string, Property> &properties)
{
    properties_ = properties;
}

void Block::setProperty(const std::string &name, double value)
{
    properties_.find(name)->second.value = value;
}

double Block::getProperty(const std::string &name) const
{
    return properties_.find(name)->second.value;
}

void Block::addSolution(const Solution &solution)
{
    solutions_[solution.symbol] = solution;
}

void Block::setNodeEquations()
{

}
