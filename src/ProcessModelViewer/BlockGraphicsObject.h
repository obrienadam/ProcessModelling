#ifndef BLOCKGRAPHICSOBJECT_H
#define BLOCKGRAPHICSOBJECT_H

#include <QGraphicsItem>
#include "processmodelviewer_global.h"
#include "Block.h"

class PROCESSMODELVIEWERSHARED_EXPORT BlockGraphicsObject : public QGraphicsItem
{
public:
    BlockGraphicsObject(Block *block);
    ~BlockGraphicsObject();

    Block* block() { return block_; }

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

private:

    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);

    void setNodes();
    void setText();
    void setTextPosition();

    Block *block_;
    QGraphicsTextItem *text_;

    std::vector<QGraphicsEllipseItem*> nodes_;
};

#endif // SINKGRAPHICSOBJECT_H
