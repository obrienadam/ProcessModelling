#include <QKeyEvent>
#include <QDebug>
#include "ProcessModelViewer.h"

ProcessModelViewer::ProcessModelViewer()
{

}

ProcessModelViewer::~ProcessModelViewer()
{
    for(BlockGraphicsObject *block: blocks_)
    {
        QGraphicsScene::removeItem(block);
        delete block;
    }

}

void ProcessModelViewer::addBlock(BlockGraphicsObject *block)
{
    processModel_.addBlock(block->block());
    this->addItem(block);
    blocks_.push_back(block);
}

void ProcessModelViewer::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
    case Qt::Key_Delete:
        for(QGraphicsItem* item: this->selectedItems())
            removeItem((BlockGraphicsObject*)item);
        qDebug() << "Block removed.";
        break;

    case Qt::Key_Left:
        for(QGraphicsItem* item: this->selectedItems())
            item->setTransform(QTransform::fromScale(-1, 1));
        break;

    case Qt::Key_Right:
        for(QGraphicsItem* item: this->selectedItems())
            item->setTransform(QTransform::fromScale(1, 1));
        break;

    default:
        break;
    }

    QGraphicsScene::keyPressEvent(event);
}

void ProcessModelViewer::deleteBlock(BlockGraphicsObject *block)
{
    this->removeItem(block);
    blocks_.erase(std::find(blocks_.begin(), blocks_.end(), block));

    processModel_.deleteBlock(block->block());
    delete block;
}
