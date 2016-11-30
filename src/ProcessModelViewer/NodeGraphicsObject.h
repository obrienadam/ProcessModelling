#ifndef NODEGRAPHICSOBJECT_H
#define NODEGRAPHICSOBJECT_H

#include <QGraphicsEllipseItem>

#include "Node.h"
#include "ConnectorGraphicsPathObject.h"

class NodeGraphicsObject : public QGraphicsEllipseItem
{
public:
    NodeGraphicsObject(Node* node, QGraphicsItem* parent);

private:

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

    ConnectorGraphicsPathObject* checkForConnection(QPointF point);

    Node* node_;
    ConnectorGraphicsPathObject *tmpPath_ = nullptr;
};

#endif // NODEGRAPHICSOBJECT_H
