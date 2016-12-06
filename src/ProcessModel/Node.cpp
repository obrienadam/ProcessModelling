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

void Node::addProperty(const std::string &name, double value, double min, double max)
{
    properties_.push_back(
                Property(name, value, min, max)
                );
}
