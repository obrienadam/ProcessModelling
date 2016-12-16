#include "Node.h"
#include "Block.h"
#include "Connector.h"

Node::Node(Type type, Block *block, Connector *connector)
    :
      type_(type),
      block_(block),
      connector_(connector)
{
    solutionVariables_["Pressure"] = Property("Pressure", "P", 101325., 0., 200000);
}

void Node::addSolutionVariable(const std::string &name, const std::string& symbol, double value, double min, double max)
{
    solutionVariables_[name] = Property(name, symbol, value, min, max);
}
