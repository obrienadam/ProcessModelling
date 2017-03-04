#ifndef NODE_H
#define NODE_H

#include <map>

#include "Property.h"
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
    const Block& block() const { return *block_; }
    void removeBlock() { block_ = nullptr; }

    //- Connector properties
    Connector& connector() { return *connector_; }
    void setConnector(Connector *connector) { connector_ = connector; }
    void removeConnector() { connector_ = nullptr; }

    //- Solution variables
    void addSolutionVariable(const std::string& name, const std::string &symbol, double value = 0., double min = 0., double max = 0.);

    void setSolutionVariable(const std::string& name, double value) { solutionVariables_[name].value = value; }
    double getSolutionVariable(const std::string& name) const { return solutionVariables_.find(name)->second.value; }

    const std::map<std::string, Property>& solutionVariables() const { return solutionVariables_; }

    //- Misc
    void setEquation(const Equation& eqn) { eqn_ = eqn; }
    Equation& equation() { return eqn_; }
    const Equation& equation() const { return eqn_; }

private:

    const Type type_;

    //- Model info
    Block *block_;
    Connector *connector_;

    //- Properties
    std::map<std::string, Property> solutionVariables_;
    Equation eqn_;
};
#endif // NODE_H
