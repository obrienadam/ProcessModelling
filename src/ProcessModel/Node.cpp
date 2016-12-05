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
