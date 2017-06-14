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

bool Connector::connect(std::shared_ptr<Node>& sourceNode, std::shared_ptr<Node>& destNode)
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

std::shared_ptr<Node> &Connector::otherNode(const std::shared_ptr<Node> &node)
{
    if(sourceNode_ == node)
        return destNode_;
    else if(destNode_ == node)
        return sourceNode_;
}
