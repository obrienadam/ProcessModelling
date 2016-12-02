#include <QGraphicsScene>
#include <QPen>
#include <QBrush>
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>
#include <QDebug>

#include "NodeGraphicsObject.h"
#include "ConnectorGraphicsPathObject.h"

NodeGraphicsObject::NodeGraphicsObject(Node *node, QGraphicsItem *parent)
    :
      QGraphicsEllipseItem(0, 0, 10, 10, parent),
      node_(node)
{
    setFlags(ItemSendsScenePositionChanges);
    setPen(QPen(Qt::black, 2));
    setBrush(QBrush(Qt::blue));
    setAcceptedMouseButtons(Qt::LeftButton);
}

NodeGraphicsObject::~NodeGraphicsObject()
{

}

void NodeGraphicsObject::removeConnection()
{
    connector_ = nullptr;
}

void NodeGraphicsObject::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    switch(event->button())
    {
    case Qt::LeftButton:
        if(connector_ == nullptr)
        {
            connector_ = new ConnectorGraphicsPathObject();
            scene()->addItem(connector_);
            event->accept();
        }
        break;
    default:
        break;
    }

    //QGraphicsEllipseItem::mousePressEvent(event); //for some incredibly stupid reason this breaks it
}

void NodeGraphicsObject::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if(!connector_->connector()->isConnected())
        connector_->setPath(this, mapToScene(event->pos()));
    //event->accept();
}

void NodeGraphicsObject::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "Node: " << this << " released event detected, type = " << (node_->isInput() ? "Input" : node_->isOutput() ? "Output" : "Sink");
    qDebug() << "Pos = " << event->pos();
    qDebug() << "Node scene pos: " << this->mapToScene(event->pos());

    if(!connector_->connector()->isConnected())
        checkForConnection(mapToScene(event->pos()));
}

QVariant NodeGraphicsObject::itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value)
{
    if(change == ItemScenePositionHasChanged)
    {
        qDebug() << "Called" << connector_;
        if(connector_)
            connector_->setPath();
    }

    return QGraphicsEllipseItem::itemChange(change, value);
}

ConnectorGraphicsPathObject *NodeGraphicsObject::checkForConnection(QPointF point)
{
    NodeGraphicsObject* destNode = nullptr;
    for(QGraphicsItem* item: scene()->items(point))
        if(item->type() == NodeGraphicsObject::Type)
        {
            destNode = (NodeGraphicsObject*)item;
            break;
        }

    if(destNode && !destNode->connector_ && connector_->connect(this, destNode))
    {
        destNode->connector_ = connector_;
    }
    else
    {
        scene()->removeItem(connector_);
        delete connector_;
        connector_ = nullptr;
    }
}
