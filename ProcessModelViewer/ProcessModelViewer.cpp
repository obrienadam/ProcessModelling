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
