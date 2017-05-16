#ifndef CONNECTOR_H
#define CONNECTOR_H

#include <memory>
#include <functional>
#include <map>

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
    Node* sourceNode() { return sourceNode_; }
    Node* destNode() { return destNode_; }
    Node* otherNode(const Node* node);

    //- Properties
    void addProperty(const Property& property);
    double getProperty(const std::string& symbol) const { return properties_.find(symbol)->second.value; }

    void addSolution(const Solution& solution) { solutions_[solution.symbol] = solution; }
    void setSolution(const std::string& name, double value) { solutions_.find(name)->second.value = value; }
    double getSolution(const std::string& name) const { return solutions_.find(name)->second.value; }

    void setResistanceFunction(std::function<double(const std::map<std::string, Property>&, const std::map<std::string, Solution>&)>& resistanceFunction)
    {
        resistance_ = resistanceFunction;
    }

    double getResistance() const { return resistance_(properties_, solutions_); }

    //- Properties
    std::map<std::string, Property>& properties() { return properties_; }
    std::map<std::string, Solution>& solution() { return solutions_; }

private:
    Node *sourceNode_, *destNode_;
    std::map<std::string, Property> properties_;
    std::map<std::string, Solution> solutions_;

    //- Resistance functional
    std::function<double(const std::map<std::string, Property>&, const std::map<std::string, Solution>&)> resistance_;
};

#endif // CONNECTOR_H
