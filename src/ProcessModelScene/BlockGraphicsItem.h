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
    BlockGraphicsItem(Block* block, const QImage& img, const std::vector<QPointF>& nodePts);
    BlockGraphicsItem(const QPointF& pos, Block* block, const QImage& img, const std::vector<QPointF> &nodePts);
    ~BlockGraphicsItem();

    //- Block
    Block* block() { return block_.get(); }

    //- Rendering
    int type() const override { return Type; }
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

protected:
    //- Helpers
    void setText();
    void setTextPosition();

    //- Events
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);

    std::shared_ptr<Block> block_;
    QGraphicsTextItem text_;

    //- Children which act as event propagators to nodes
    std::vector<NodeGraphicsItem*> nodes_;
};

#endif // SINKGRAPHICSOBJECT_H
