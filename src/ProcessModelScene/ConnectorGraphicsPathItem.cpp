#include <QGraphicsScene>
#include <QPen>
#include <QGraphicsSceneMouseEvent>

#include "ConnectorGraphicsPathItem.h"
#include "NodeGraphicsItem.h"
#include "PropertyDialog.h"

ConnectorGraphicsPathItem::ConnectorGraphicsPathItem()
    :
      sourceNode_(nullptr),
      destNode_(nullptr),
      connector_(nullptr)
{
    setPen(QPen(Qt::black, 3));
    setFlags(ItemIsSelectable);
}

ConnectorGraphicsPathItem::~ConnectorGraphicsPathItem()
{
    if(scene())
        scene()->removeItem(this);

    if(isConnected())
        disconnect();
}

void ConnectorGraphicsPathItem::setSourceNode(NodeGraphicsItem *sourceNode)
{
    sourceNode_ = sourceNode;
    resetPath();
}

void ConnectorGraphicsPathItem::setPathTo(const QPointF &pos)
{
    if(sourceNode_)
        computePath(sourceNode_->mapToScene(sourceNode_->boundingRect().center()), pos);
}

void ConnectorGraphicsPathItem::resetPath()
{
    setPath(QPainterPath());
}

void ConnectorGraphicsPathItem::update(const QRectF &rect)
{
    if(isConnected())
    {
        computePath(
                    sourceNode_->mapToScene(sourceNode_->boundingRect().center()),
                    destNode_->mapToScene(destNode_->boundingRect().center())
                    );
    }

    QGraphicsPathItem::update(rect);
}

std::shared_ptr<Connector> ConnectorGraphicsPathItem::connect(NodeGraphicsItem *destNode)
{
    if(!sourceNode_ || sourceNode_->isConnected() || destNode->isConnected())
        return nullptr;

    connector_ = std::shared_ptr<Connector>(new Connector());

    if(connector_->connect(sourceNode_->node(),
                           destNode->node()))
    {
        destNode_ = destNode;
        sourceNode_->addConnection(this);
        destNode_->addConnection(this);

        update();
        return connector_;
    }
    else
        connector_ = nullptr;

    return connector_;
}

void ConnectorGraphicsPathItem::disconnect()
{
    if(isConnected())
    {
        connector_ = nullptr;

        sourceNode_->removeConnection();
        destNode_->removeConnection();
    }
}

void ConnectorGraphicsPathItem::computePath(const QPointF &start, const QPointF &end)
{
    QPointF rVec = QPointF((end - start).x(), 0);

    QPainterPath path(start);
    path.cubicTo(
                start + 0.3*rVec,
                end - 0.3*rVec,
                end
                );

    QGraphicsPathItem::setPath(path);
}

void ConnectorGraphicsPathItem::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    PropertyDialog dialog("Connector",
                          "Connector Properties",
                          connector_->properties(),
                          connector_->solution(),
                          nullptr);

    if(dialog.exec() == QDialog::Accepted)
        connector_->setProperties(dialog.properties());
}
