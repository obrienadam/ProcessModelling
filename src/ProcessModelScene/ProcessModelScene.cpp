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
    model_ = std::make_shared<SimpleLinearModel>();
}

ProcessModelScene::~ProcessModelScene()
{
    delete tmpConnector_;
}

void ProcessModelScene::addBlock(Block *block, const QImage &img, const std::vector<QPointF>& nodePts, const QPointF &scenePos)
{
    BlockGraphicsItem *blockItem = new BlockGraphicsItem(block, img, nodePts);
    blockItem->setPos(scenePos);
    addItem(blockItem);
}

std::vector<Block *> ProcessModelScene::getBlocks()
{
    std::vector<Block*> blocks;

    for(QGraphicsItem* item: this->items())
    {
        if(item->type() == BlockGraphicsItem::Type)
            blocks.push_back(qgraphicsitem_cast<BlockGraphicsItem*>(item)->block());
    }

    return blocks;
}

std::vector<Connector *> ProcessModelScene::getConnectors()
{
    std::vector<Connector*> connectors;

    for(QGraphicsItem* item: this->items())
    {
        if(item->type() == ConnectorGraphicsPathItem::Type)
            connectors.push_back(qgraphicsitem_cast<ConnectorGraphicsPathItem*>(item)->connector().get());
    }

    return connectors;
}

void ProcessModelScene::setNewModel(const std::shared_ptr<Model> &model)
{
    model_ = model;
    model_->initialize(getConnectors());
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
            model_->initialize(tmpConnector_->connector().get());
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
