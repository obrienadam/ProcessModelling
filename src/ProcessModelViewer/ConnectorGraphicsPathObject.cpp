#include <QPen>

#include "ConnectorGraphicsPathObject.h"
#include "NodeGraphicsObject.h"

ConnectorGraphicsPathObject::ConnectorGraphicsPathObject()
{
    setPen(QPen(Qt::black, 3));
    setFlags(ItemIsSelectable);
}

void ConnectorGraphicsPathObject::setPath(NodeGraphicsObject *node, const QPointF& scenePos)
{
    computePath(node->mapToScene(node->boundingRect().center()), scenePos);
}

void ConnectorGraphicsPathObject::connectNodes(NodeGraphicsObject *startNode, NodeGraphicsObject *endNode)
{
    QPointF start = startNode->mapToScene(startNode->boundingRect().center());
    QPointF end = endNode->mapToScene(endNode->boundingRect().center());

    computePath(start, end);
}

void ConnectorGraphicsPathObject::computePath(const QPointF &start, const QPointF &end)
{
    QPointF rVec = QPointF((end - start).x(), 0);

    QPainterPath path(start);
    path.cubicTo(
                start + 0.4*rVec,
                end - 0.4*rVec,
                end
                );

    QGraphicsPathItem::setPath(path);
}
