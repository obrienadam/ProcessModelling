#include "Node.h"
#include "Block.h"
#include "Connector.h"

Node::Node(Type type, Block *block, Connector *connector)
    :
      type_(type),
      block_(block),
      connector_(connector)
{

}

void Node::addProperty(const std::string &name, const std::string& symbol, double value, double min, double max)
{
    properties_.push_back(
                Property(name, symbol, value, min, max)
                );
}
