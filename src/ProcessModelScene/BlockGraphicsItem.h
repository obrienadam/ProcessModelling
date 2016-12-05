#ifndef BLOCKGRAPHICSITEM_H
#define BLOCKGRAPHICSITEM_H

#include <memory>

#include <QGraphicsPixmapItem>
#include "Block.h"
#include "NodeGraphicsItem.h"

class BlockGraphicsItem : public QGraphicsPixmapItem
{
public:

    enum {Type = UserType + 1};

    //- Constructors/destructors
    BlockGraphicsItem(Block* block, const QImage& img);
    ~BlockGraphicsItem();

    //- Block
    Block* block() { return block_; }

    //- Rendering
    int type() const override { return Type; }
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

protected:
    static QPointF np_[10];

    //- Helpers
    void setText();
    void setTextPosition();

    //- Events
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);

    Block *block_;
    QGraphicsTextItem text_;

    //- Children which act as event propagators to nodes
    std::vector<NodeGraphicsItem*> nodes_;
};

#endif // SINKGRAPHICSOBJECT_H
