#include <QGraphicsScene>
#include <QPen>
#include <QBrush>
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>
#include <QDebug>

#include "NodeGraphicsItem.h"
#include "BlockGraphicsItem.h"
#include "ConnectorGraphicsPathItem.h"

NodeGraphicsItem::NodeGraphicsItem(std::shared_ptr<Node> &node, BlockGraphicsItem *block)
    :
      QGraphicsEllipseItem(0, 0, 10, 10, block),
      node_(node),
      connector_(nullptr)
{
    setPen(QPen(Qt::black, 2));
    setBrush(node_->isInput() ? Qt::white : node_->isOutput() ? Qt::black : Qt::gray);
}

NodeGraphicsItem::~NodeGraphicsItem()
{
    if(scene())
        scene()->removeItem(this);
    if(connector_)
        delete connector_;
}

void NodeGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(connector_)
        connector_->update();

    QGraphicsEllipseItem::paint(painter, option, widget);
}

void NodeGraphicsItem::removeConnection()
{
    connector_ = nullptr;
}

