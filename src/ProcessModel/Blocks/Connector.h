#ifndef CONNECTOR_H
#define CONNECTOR_H

#include <memory>
#include <functional>
#include <map>

#include "processmodel_global.h"
#include "Node.h"
#include "FlowModel.h"

class PROCESSMODELSHARED_EXPORT Connector
{
public:
    Connector();
    ~Connector();

    //- Connecting
    bool isConnected() const { return sourceNode_ && destNode_; }

    bool canConnect(const Node& sourceNode, const Node& destNode) const;

    bool connect(std::shared_ptr<Node> &sourceNode, std::shared_ptr<Node> &destNode);

    void disconnect();

    //- Access
    std::shared_ptr<Node>& sourceNode() { return sourceNode_; }

    std::shared_ptr<Node>& destNode() { return destNode_; }

    std::shared_ptr<Node>& otherNode(const std::shared_ptr<Node> &node);

    //- State
    void setState(const std::shared_ptr<FlowModel::ConnectorState>& state)
    { state_ = state; }

    FlowModel::ConnectorState& state()
    { return *state_; }

    const FlowModel::ConnectorState& state() const
    { return *state_; }

    double resistance() const
    { return state_->resistance(); }

    //- Properties
    void setProperties(const std::map<std::string, double>& properties)
    { state_->setProperties(properties); }

    std::map<std::string, double> properties() const
    { return state_->properties(); }

    //- Solution
    std::map<std::string, double> solution() const
    { return state_->solution(); }

private:

    std::shared_ptr<Node> sourceNode_, destNode_;
    std::shared_ptr<FlowModel::ConnectorState> state_;
};

#endif // CONNECTOR_H
