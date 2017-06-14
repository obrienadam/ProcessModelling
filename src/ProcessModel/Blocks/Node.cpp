#include "Node.h"
#include "Block.h"
#include "Connector.h"

Node::Node(Type type, Block *block)
    :
      type_(type),
      block_(block)
{

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
