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

    //- Properties
    void addProperty(const std::string& name, const std::string &symbol, double value = 0., double min = 0., double max = 0.);
    void setProperties(const std::map<std::string, Property> &properties);

    void setSolutionVariable(const std::string& name, double value) { solution_[name].value = value; }
    void setSolutionVariables(const std::map<std::string, Property> &solutionVariables);

    void setResistanceFunction(std::function<double(const std::map<std::string, Property>&, const std::map<std::string, Property>&)>& resistanceFunction)
    {
        resistance_ = resistanceFunction;
    }

    double getSolutionVariable(const std::string& var) const { return solution_.find(var)->second.value; }
    double getResistance() const { return resistance_(properties_, solution_); }

    //- Properties
    std::map<std::string, Property>& properties() { return properties_; }
    std::map<std::string, Property>& solution() { return solution_; }

private:
    Node *sourceNode_, *destNode_;
    std::map<std::string, Property> properties_;
    std::map<std::string, Property> solution_;

    //- Resistance functional
    std::function<double(const std::map<std::string, Property>&, const std::map<std::string, Property>&)> resistance_;
};

#endif // CONNECTOR_H
