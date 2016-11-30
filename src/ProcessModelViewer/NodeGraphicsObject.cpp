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
    setPen(QPen(Qt::black, 2));
    setBrush(QBrush(Qt::blue));
    setAcceptedMouseButtons(Qt::LeftButton);
}

void NodeGraphicsObject::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    switch(event->button())
    {
    case Qt::LeftButton:
        tmpPath_ = new ConnectorGraphicsPathObject();
        scene()->addItem(tmpPath_);
        event->accept();

        break;
    default:
        break;
    }

    //QGraphicsEllipseItem::mousePressEvent(event); //for some incredibly stupid reason this breaks it
}

void NodeGraphicsObject::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    tmpPath_->setPath(this, mapToScene(event->pos()));
    //event->accept();
}

void NodeGraphicsObject::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "Node: " << this << " released event detected, type = " << (node_->isInput() ? "Input" : node_->isOutput() ? "Output" : "Sink");
    qDebug() << "Pos = " << event->pos();
    qDebug() << "Node scene pos: " << this->mapToScene(event->pos());

    scene()->removeItem(tmpPath_);
    delete tmpPath_;
    tmpPath_ = nullptr;

    checkForConnection(mapToScene(event->pos()));
}

ConnectorGraphicsPathObject *NodeGraphicsObject::checkForConnection(QPointF point)
{
    NodeGraphicsObject *item = (NodeGraphicsObject*)scene()->itemAt(point, transform());
    qDebug() << item;

    if(item == nullptr)
        return nullptr;

    Connector connector;
    if(connector.connect(*(this->node_), *(item->node_)))
    {
        ConnectorGraphicsPathObject *cp = new ConnectorGraphicsPathObject();
        cp->connectNodes(this, item);
        scene()->addItem(cp);
    }
    else
    {
        qDebug() << "Nodes could not be connected.";
    }
}
