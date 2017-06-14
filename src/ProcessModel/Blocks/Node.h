#ifndef NODE_H
#define NODE_H

#include <map>

#include "Equation.h"
#include "FlowModel.h"

class Block;
class Connector;

class Node
{
public:
    enum Type{INPUT, OUTPUT, SINK};

    Node(Type type, Block *block);

    //- Node type info
    bool isInput() const
    { return type_ == INPUT; }

    bool isOutput() const
    { return type_ == OUTPUT; }

    bool isSink() const
    { return type_ == SINK; }

    std::string type() const;

    //- Block info
    Block& block()
    { return *block_; }

    const Block& block() const
    { return *block_; }

    void removeBlock()
    { block_ = nullptr; }

    //- Connector info
    Connector& connector()
    { return *connector_; }

    void setConnector(Connector *connector)
    { connector_ = connector; }

    void removeConnector()
    { connector_ = nullptr; }

    //- State info

    void setState(const std::shared_ptr<FlowModel::NodeState>& state)
    { state_ = state; }

    FlowModel::NodeState& state()
    { return *state_; }

    const FlowModel::NodeState& state() const
    { return *state_; }

    //- Misc
    void setEquation(const Equation& eqn) { eqn_ = eqn; }

    Equation& equation() { return eqn_; }

    const Equation& equation() const { return eqn_; }

private:

    const Type type_;

    //- Model info
    Block *block_;
    Connector *connector_ = nullptr;

    //- State
    std::shared_ptr<FlowModel::NodeState> state_;

    Equation eqn_;
};
#endif // NODE_H
