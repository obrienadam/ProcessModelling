#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>
#include <QDebug>
#include "ProcessModelScene.h"

//- Private helper methods
ProcessModelScene::ProcessModelScene(QObject *parent)
    :
      QGraphicsScene(parent)
{
    setObjectName("Process Model Scene");
    tmpConnector_ = new ConnectorGraphicsPathItem();
}

ProcessModelScene::~ProcessModelScene()
{
    delete tmpConnector_;
}

void ProcessModelScene::addBlock(Block *block, const QImage &img, const QPointF &scenePos)
{
    BlockGraphicsItem *blockItem = new BlockGraphicsItem(block, img);
    blockItem->setPos(scenePos);
    addItem(blockItem);
}

void ProcessModelScene::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
    case Qt::Key_Delete:
        for(QGraphicsItem* item: selectedItems())
        {
            switch(item->type())
            {
            case BlockGraphicsItem::Type:
            case ConnectorGraphicsPathItem::Type:
                delete item;
            }
        }
        break;

    case Qt::Key_Left:
        for(QGraphicsItem* item: this->selectedItems())
            switch(item->type())
            {
            case BlockGraphicsItem::Type:
                item->setTransform(QTransform::fromScale(-1, 1));
                break;
            }

        break;

    case Qt::Key_Right:
        for(QGraphicsItem* item: this->selectedItems())
            switch(item->type())
            {
            case BlockGraphicsItem::Type:
                item->setTransform(QTransform::fromScale(1, 1));
                break;
            }
        break;

    default:
        break;
    }

    QGraphicsScene::keyPressEvent(event);
}

void ProcessModelScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    NodeGraphicsItem* node = nodeAt(event->scenePos());

    if(node && !node->isConnected())
    {
        tmpConnector_->setSourceNode(node);
        addItem(tmpConnector_);
        event->accept();
    }

    QGraphicsScene::mousePressEvent(event);
}

void ProcessModelScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if(tmpConnector_->scene())
        tmpConnector_->setPathTo(event->scenePos());

    QGraphicsScene::mouseMoveEvent(event);
}

void ProcessModelScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if(tmpConnector_->scene())
    {
        NodeGraphicsItem *node = nodeAt(event->scenePos());

        if(node && tmpConnector_->connect(node))
        {
            qDebug() << "CONNECTION BABY";
            tmpConnector_ = new ConnectorGraphicsPathItem();
        }
        else
            removeItem(tmpConnector_);
    }

    QGraphicsScene::mouseReleaseEvent(event);
}

BlockGraphicsItem *ProcessModelScene::blockAt(const QPointF &scenePos)
{
    for(QGraphicsItem* item: items(scenePos))
    {
        if(item->type() == BlockGraphicsItem::Type)
            return (BlockGraphicsItem*)item;
    }

    return nullptr;
}

ConnectorGraphicsPathItem *ProcessModelScene::connectorAt(const QPointF &scenePos)
{
    for(QGraphicsItem* item: items(scenePos))
    {
        if(item->type() == ConnectorGraphicsPathItem::Type)
            return (ConnectorGraphicsPathItem*)item;
    }

    return nullptr;
}

NodeGraphicsItem *ProcessModelScene::nodeAt(const QPointF &scenePos)
{
    for(QGraphicsItem* item: items(scenePos))
    {
        if(item->type() == NodeGraphicsItem::Type)
            return (NodeGraphicsItem*)item;
    }

    return nullptr;
}
