#ifndef CONNECTOR_H
#define CONNECTOR_H

#include "processmodel_global.h"
#include "Node.h"

class PROCESSMODELSHARED_EXPORT Connector
{
public:
    Connector();

    bool isSourceNode(Node* node) const { return node == sourceNode_ ; }

    bool canConnect(const Node& sourceNode, const Node& destNode) const;
    bool isConnected() const { return sourceNode_ != nullptr && destNode_ != nullptr; }

    bool connect(Node* sourceNode, Node* destNode);

private:
    Node *sourceNode_ = nullptr, *destNode_ = nullptr;
};

#endif // CONNECTOR_H
