#include "Node.h"
#include "Block.h"
#include "Connector.h"

Node::Node(Type type, Block *block, Connector *connector)
    :
      type_(type),
      block_(block),
      connector_(connector)
{
    addSolution(Solution("P", "Pressure"));
}

std::string Node::type() const
{
    switch(type_)
    {
    case INPUT: return "input";
    case OUTPUT: return "output";
    case SINK: return "sink";
    }
}

void Node::addSolution(const Solution& solution)
{
    solutions_[solution.symbol] = solution;
}
