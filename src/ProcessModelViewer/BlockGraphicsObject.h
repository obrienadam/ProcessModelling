#ifndef BLOCKGRAPHICSOBJECT_H
#define BLOCKGRAPHICSOBJECT_H

#include <QGraphicsRectItem>
#include "processmodelviewer_global.h"
#include "Block.h"
#include "NodeGraphicsObject.h"

class PROCESSMODELVIEWERSHARED_EXPORT BlockGraphicsObject : public QGraphicsRectItem
{
public:

    enum {Type = UserType + 1};

    int type() const { return Type; }

    BlockGraphicsObject(Block *block);
    ~BlockGraphicsObject();

    Block* block() { return block_; }
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

protected:

    void setNodes();
    void setText();
    void setTextPosition();

    Block *block_;
    QGraphicsTextItem *text_;

    std::vector<NodeGraphicsObject*> nodes_;
};

#endif // SINKGRAPHICSOBJECT_H
