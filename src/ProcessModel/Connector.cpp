#include "Connector.h"

Connector::Connector()
    :
      sourceNode_(nullptr),
      destNode_(nullptr)
{

}

bool Connector::canConnect(const Node &sourceNode, const Node &destNode) const
{
    return (sourceNode.isSink() && destNode.isInput())
            || (sourceNode.isOutput() && destNode.isInput())
            || (sourceNode.isOutput() && destNode.isSink())
            || (sourceNode.isSink() && destNode.isSink());
}

bool Connector::connect(Node &sourceNode, Node &destNode)
{
    if(!canConnect(sourceNode, destNode))
        return false;

    sourceNode_ = &sourceNode;
    destNode_ = &destNode;

    return true;
}
