#include "NodeGraphicsObject.h"

NodeGraphicsObject::NodeGraphicsObject(Node *node, BlockGraphicsObject *block)
    :
      QGraphicsItem(block),
      node_(node)
{

}
