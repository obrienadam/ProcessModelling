#ifndef NODE_H
#define NODE_H

#include <vector>
#include "Equation.h"

class Block;
class Connector;

class Node
{
public:
    enum Type{INPUT, OUTPUT, SINK};

    Node(Type type, Block *block = nullptr, Connector *connector = nullptr);

    //- Block properties
    bool isInput() const { return type_ == INPUT; }
    bool isOutput() const { return type_ == OUTPUT; }
    bool isSink() const { return type_ == SINK; }

    Block& block() { return *block_; }
    void removeBlock() { block_ = nullptr; }

    //- Connector properties
    Connector& connector() { return *connector_; }
    void setConnector(Connector *connector) { connector_ = connector; }
    void removeConnector() { connector_ = nullptr; }

    //- Misc
    Equation& equation() { return eqn_; }
    const Equation& equation() const { return eqn_; }
    const Block* block() const { return block_; }

private:

    const Type type_;

    //- Model info
    Block *block_;
    Connector *connector_;

    //- Properties
    std::vector<double> props_;
    Equation eqn_;
};
#endif // NODE_H
