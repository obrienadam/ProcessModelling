#ifndef BLOCK_H
#define BLOCK_H

#include <string>
#include <memory>
#include <Node.h>
#include <map>

#include "Property.h"

class Block
{
public:

    Block(int nInputs,
          int nOutputs,
          int nSinks,
          const std::string& type, const std::string& name = "Block");

    ~Block();

    //- Node info
    size_t nInputs() const { return inputs_.size(); }
    size_t nOutputs() const { return outputs_.size(); }
    size_t nSinks() const { return sinks_.size(); }
    size_t nNodes() const { return nodes_.size(); }

    std::vector<std::shared_ptr<Node>>& inputs() { return inputs_; }
    std::vector<std::shared_ptr<Node>>& outputs() { return outputs_; }
    std::vector<std::shared_ptr<Node>>& sinks() { return sinks_; }
    std::vector<std::shared_ptr<Node>>& nodes() { return nodes_; }

    //- Iterator
    std::vector<std::shared_ptr<Node>>::iterator begin() { return nodes_.begin(); }
    std::vector<std::shared_ptr<Node>>::iterator end() { return nodes_.end(); }

    //- General info
    const std::string& getName() const { return name; }
    const std::string& getType() const { return type; }

    //- Properties
    void addProperty(const std::string& name, const std::string &symbol, double value = 0., double min = 0., double max = 100.);
    void setProperties(const std::map<std::string, Property> &properties);

    //- Equations
    virtual void setNodeEquations();

    //- Properties
    std::map<std::string, Property>& properties() { return properties_; }
    std::map<std::string, Property>& solution() { return solution_; }

    const std::string type;
    std::string name;

protected:
    std::vector<std::shared_ptr<Node>> inputs_;
    std::vector<std::shared_ptr<Node>> outputs_;
    std::vector<std::shared_ptr<Node>> sinks_;
    std::vector<std::shared_ptr<Node>> nodes_;

    //- Properties
    std::map<std::string, Property> properties_;
    std::map<std::string, Property> solution_;
    std::map<std::string, std::vector<std::string>> options_;
};

#include "Fan.h"
#include "ConstFlowFan.h"
#include "PressureReservoir.h"
#include "MassFlowReservoir.h"
#include "Valve.h"
#include "Diffuser.h"
#include "Nozzle.h"
#include "Tee.h"

#endif // BLOCK_H
