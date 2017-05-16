#ifndef BLOCK_H
#define BLOCK_H

#include <string>
#include <memory>
#include <Node.h>
#include <map>

#include "processmodel_global.h"
#include "Property.h"
#include "Solution.h"

class PROCESSMODELSHARED_EXPORT Block
{
public:

    Block(int nInputs,
          int nOutputs,
          int nSinks, const std::string& name = "Block");

    ~Block();

    //- Node info
    size_t nInputs() const
    { return inputs_.size(); }

    size_t nOutputs() const
    { return outputs_.size(); }

    size_t nSinks() const
    { return sinks_.size(); }

    size_t nNodes() const
    { return nodes_.size(); }

    std::vector<std::shared_ptr<Node>>& inputs()
    { return inputs_; }

    std::vector<std::shared_ptr<Node>>& outputs()
    { return outputs_; }

    std::vector<std::shared_ptr<Node>>& sinks()
    { return sinks_; }

    std::vector<std::shared_ptr<Node>>& nodes()
    { return nodes_; }

    //- Iterator
    std::vector<std::shared_ptr<Node>>::iterator begin()
    { return nodes_.begin(); }

    std::vector<std::shared_ptr<Node>>::iterator end()
    { return nodes_.end(); }

    //- General info

    virtual std::string type() const = 0;

    //- Properties
    void addProperty(const Property& property);

    void setProperties(const std::map<std::string, Property> &properties);

    void setProperty(const std::string& name, double value);

    double getProperty(const std::string& name) const;

    //- Solution
    void addSolution(const Solution& solution);

    void setSolution(const std::string& name, double value)
    { solutions_.find(name)->second.value = value; }

    double getSolution(const std::string& name) const
    { return solutions_.find(name)->second.value; }

    virtual void updateSolution() {}

    //- Equations
    virtual void setNodeEquations();

    //- Properties
    std::map<std::string, Property>& properties()
    { return properties_; }

    std::map<std::string, Solution>& solution()
    { return solutions_; }

    std::string name;

protected:
    std::vector<std::shared_ptr<Node>> inputs_;

    std::vector<std::shared_ptr<Node>> outputs_;

    std::vector<std::shared_ptr<Node>> sinks_;

    std::vector<std::shared_ptr<Node>> nodes_;

    //- Properties
    std::map<std::string, Property> properties_;

    std::map<std::string, Solution> solutions_;

    std::map<std::string, std::vector<std::string>> options_;
};

#include "Fan.h"
#include "ConstFlowFan.h"
#include "PressureReservoir.h"
#include "MassFlowReservoir.h"
#include "Valve.h"
#include "RestrictorValve.h"
#include "Diffuser.h"
#include "Nozzle.h"
#include "YConnector.h"

#endif // BLOCK_H
