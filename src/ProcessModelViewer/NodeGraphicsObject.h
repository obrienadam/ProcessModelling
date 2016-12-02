#ifndef NODEGRAPHICSOBJECT_H
#define NODEGRAPHICSOBJECT_H

#include <QGraphicsEllipseItem>

#include "Node.h"
#include "ConnectorGraphicsPathObject.h"

class NodeGraphicsObject : public QGraphicsEllipseItem
{
public:

    enum {Type = UserType + 3};

    NodeGraphicsObject(Node* node, QGraphicsItem* parent);
    ~NodeGraphicsObject();

    int type() const override { return Type; }

    void removeConnection();

    Node* node() { return node_; }

private:

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

    QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;

    ConnectorGraphicsPathObject* checkForConnection(QPointF point);

    Node* node_;
    ConnectorGraphicsPathObject *connector_ = nullptr;
};

#endif // NODEGRAPHICSOBJECT_H
