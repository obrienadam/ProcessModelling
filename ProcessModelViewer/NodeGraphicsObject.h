#ifndef NODEGRAPHICSOBJECT_H
#define NODEGRAPHICSOBJECT_H

#include <QGraphicsItem>

#include "node.h"
#include "BlockGraphicsObject.h"

class NodeGraphicsObject : public QGraphicsItem
{
public:
    NodeGraphicsObject(Node* node, BlockGraphicsObject* block);

private:
    Node* node_;
};

#endif // NODEGRAPHICSOBJECT_H
