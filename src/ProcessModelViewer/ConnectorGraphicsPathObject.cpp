#include <QPen>

#include "ConnectorGraphicsPathObject.h"
#include "NodeGraphicsObject.h"

ConnectorGraphicsPathObject::ConnectorGraphicsPathObject()
{
    setPen(QPen(Qt::black, 3));
    setFlags(ItemIsSelectable);
    connector_ = new Connector();
}

ConnectorGraphicsPathObject::~ConnectorGraphicsPathObject()
{
    delete connector_;
}

void ConnectorGraphicsPathObject::setPath(NodeGraphicsObject *node, const QPointF& scenePos)
{
    computePath(node->mapToScene(node->boundingRect().center()), scenePos);
}

void ConnectorGraphicsPathObject::setPath()
{
    computePath(
                sourceNode_->mapToScene(sourceNode_->boundingRect().center()),
                destNode_->mapToScene(destNode_->boundingRect().center())
                );
}

bool ConnectorGraphicsPathObject::connect(NodeGraphicsObject *sourceNode, NodeGraphicsObject *destNode)
{
    bool connected = connector_->connect(sourceNode->node(), destNode->node());
    if(connected)
    {
        QPointF start = sourceNode->mapToScene(sourceNode->boundingRect().center());
        QPointF end = destNode->mapToScene(destNode->boundingRect().center());
        computePath(start, end);
        sourceNode_ = sourceNode;
        destNode_ = destNode;
    }

    return connected;
}

void ConnectorGraphicsPathObject::disconnect()
{
    sourceNode_->removeConnection();
    destNode_->removeConnection();
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
