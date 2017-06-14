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
    BlockGraphicsItem(std::shared_ptr<Block>& block, const QImage& img, const std::vector<QPointF>& nodePts);

    ~BlockGraphicsItem();

    //- Block
    std::shared_ptr<Block>& block() { return block_; }

    //- NodeGraphicsItems
    std::vector<std::shared_ptr<NodeGraphicsItem>>& nodes()
    { return nodes_; }

    //- Qt rendering methods
    int type() const override
    { return Type; }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

    //- Misc
    void setName(const std::string& name);

    void flipHorizontal();

protected:
    //- Helpers
    void setText();

    void setTextPosition();

    //- Events
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);

    std::shared_ptr<Block> block_;

    QGraphicsTextItem text_;

    //- Children which act as event propagators to nodes
    std::vector<std::shared_ptr<NodeGraphicsItem>> nodes_;
};

#endif // SINKGRAPHICSOBJECT_H
