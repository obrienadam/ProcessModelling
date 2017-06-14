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
    if(tmpConnector_)
        delete tmpConnector_;
}

BlockGraphicsItem* ProcessModelScene::addBlock(std::shared_ptr<Block> &block,
                                               const QImage &img,
                                               const std::vector<QPointF>& nodePts,
                                               const QPointF &scenePos)
{
    BlockGraphicsItem* blockItem = new BlockGraphicsItem(block, img, nodePts);
    blockItem->setPos(scenePos);
    addItem(blockItem); //- Add to scene

    //- Make sure nodes have correct state
    flowModel_->initialize(block);

    return blockItem;
}

ConnectorGraphicsPathItem *ProcessModelScene::connect(std::shared_ptr<NodeGraphicsItem> &source, std::shared_ptr<NodeGraphicsItem> &dest)
{
    ConnectorGraphicsPathItem * connector = new ConnectorGraphicsPathItem();
    connector->setSourceNode(source.get());

    if(connector->connect(dest.get()))
    {
        addItem(connector);
        flowModel_->initialize(connector->connector());
        return connector;
    }

    delete connector;
    return nullptr;
}

std::vector<std::shared_ptr<Block>> ProcessModelScene::getBlocks()
{
    std::vector<std::shared_ptr<Block>> blocks;

    for(QGraphicsItem* item: this->items())
    {
        if(item->type() == BlockGraphicsItem::Type)
            blocks.push_back(qgraphicsitem_cast<BlockGraphicsItem*>(item)->block());
    }

    return blocks;
}

std::vector<std::shared_ptr<Connector> > ProcessModelScene::getConnectors()
{
    std::vector<std::shared_ptr<Connector>> connectors;

    for(QGraphicsItem* item: this->items())
    {
        if(item->type() == ConnectorGraphicsPathItem::Type)
            connectors.push_back(qgraphicsitem_cast<ConnectorGraphicsPathItem*>(item)->connector());
    }

    return connectors;
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
                static_cast<BlockGraphicsItem*>(item)->flipHorizontal();
                break;
            }

        break;

    case Qt::Key_Right:
        for(QGraphicsItem* item: this->selectedItems())
            switch(item->type())
            {
            case BlockGraphicsItem::Type:
                static_cast<BlockGraphicsItem*>(item)->flipHorizontal();
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
    NodeGraphicsItem* node = getItem<NodeGraphicsItem>(event->scenePos());

    if(node && !node->isConnected()) //- Found a non-connected node at press point
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
        NodeGraphicsItem *node = getItem<NodeGraphicsItem>(event->scenePos());

        if(node && tmpConnector_->connect(node))
        {
            flowModel_->initialize(tmpConnector_->connector());
            tmpConnector_ = new ConnectorGraphicsPathItem();
        }
        else
            removeItem(tmpConnector_);
    }

    QGraphicsScene::mouseReleaseEvent(event);
}
