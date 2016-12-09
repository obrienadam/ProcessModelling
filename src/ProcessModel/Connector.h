#ifndef CONNECTOR_H
#define CONNECTOR_H

#include <memory>

#include "processmodel_global.h"
#include "Node.h"

class PROCESSMODELSHARED_EXPORT Connector
{
public:
    Connector();
    ~Connector();

    //- Connecting
    bool isConnected() const { return sourceNode_ && destNode_; }
    bool canConnect(const Node& sourceNode, const Node& destNode) const;
    bool connect(Node* sourceNode, Node* destNode);
    void disconnect();

    //- Access
    Node* destNode() { return destNode_; }

    //- Properties
    void addProperty(const std::string& name, const std::string &symbol, double value = 0., double min = 0., double max = 0.);
    void setProperties(const std::vector<Property>& properties);
    std::vector<Property>& properties() { return properties_; }

private:
    Node* sourceNode_, *destNode_;
    std::vector<Property> properties_;
};

#endif // CONNECTOR_H
