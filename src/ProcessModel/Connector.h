#ifndef CONNECTOR_H
#define CONNECTOR_H

#include "processmodel_global.h"
#include "Node.h"

class PROCESSMODELSHARED_EXPORT Connector
{
public:
    Connector();

    bool canConnect(const Node& sourceNode, const Node& destNode) const;
    bool connect(Node& sourceNode, Node& destNode);

private:
    Node *sourceNode_, *destNode_;
};

#endif // CONNECTOR_H
