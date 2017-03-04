#include "Connector.h"

Connector::Connector()
    :
      sourceNode_(nullptr),
      destNode_(nullptr)
{

}

Connector::~Connector()
{
    disconnect();
}

bool Connector::canConnect(const Node &sourceNode, const Node &destNode) const
{
    return ((sourceNode.isSink() && destNode.isInput())
            || (sourceNode.isOutput() && destNode.isInput())
            || (sourceNode.isOutput() && destNode.isSink())
            || (sourceNode.isSink() && destNode.isSink()))
            && &sourceNode.block() != &destNode.block();
}

bool Connector::connect(Node* sourceNode, Node* destNode)
{
    if(!canConnect(*sourceNode, *destNode))
        return false;

    sourceNode_ = sourceNode;
    sourceNode_->setConnector(this);

    destNode_ = destNode;
    destNode_->setConnector(this);

    return true;
}

void Connector::disconnect()
{
    if(isConnected())
    {
        sourceNode_->removeConnector();
        destNode_->removeConnector();
        sourceNode_ = nullptr;
        destNode_ = nullptr;
    }
}

Node *Connector::otherNode(const Node *node)
{
    if(sourceNode_ == node)
        return destNode_;
    else if(destNode_ == node)
        return sourceNode_;
    else
        return nullptr;
}

void Connector::addProperty(const std::string &name, const std::string& symbol, double value, double min, double max)
{
    properties_[name] = Property(name, symbol, value, min, max);
}

void Connector::setProperties(const std::map<std::string, Property> &properties)
{
    properties_ = properties;
}

void Connector::setSolutionVariables(const std::map<std::string, Property> &solutionVariables)
{
    solution_ = solutionVariables;
}
