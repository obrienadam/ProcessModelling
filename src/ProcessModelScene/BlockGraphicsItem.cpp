#include <QPainter>
#include <QTextDocument>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QStyleOptionGraphicsItem>
#include <QDebug>

#include "BlockGraphicsItem.h"
#include "BlockPropertyDialog.h"

QPointF BlockGraphicsItem::np_[] = {QPointF(-10, 19), QPointF(48, 19), QPointF(20, -10)};

BlockGraphicsItem::BlockGraphicsItem(Block *block, const QImage &img)
    :
      QGraphicsPixmapItem(QPixmap::fromImage(img)),
      block_(block),
      text_(this)
{
    setFlags(ItemIsSelectable|ItemIsMovable);
    setText();

    int i = 0;
    for(auto& node: *block)
    {
        nodes_.push_back(new NodeGraphicsItem(node.get(), this));
        nodes_.back()->setPos(np_[i++]);
    }
}

BlockGraphicsItem::~BlockGraphicsItem()
{
    if(scene())
        scene()->removeItem(this);

    for(NodeGraphicsItem* node: nodes_)
        delete node;

    delete block_;
}

//- Rendering
void BlockGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(text_.document()->isModified())
    {
        block_->name = text_.toPlainText().toStdString();
        text_.document()->setModified(false);
    }
    setTextPosition();
    QGraphicsPixmapItem::paint(painter, option, widget);
}

void BlockGraphicsItem::setText()
{
    text_.setPlainText(block_->name.c_str());
    text_.setTextInteractionFlags(Qt::TextEditable|Qt::TextSelectableByKeyboard);
    text_.setFlag(QGraphicsItem::ItemIgnoresTransformations);
    setTextPosition();
}

void BlockGraphicsItem::setTextPosition()
{
    qreal w = text_.boundingRect().width();
    QPointF newPos = mapFromScene(QPointF(mapToScene(boundingRect().center()).x() - w/2., 0));

    text_.setPos(QPointF(newPos.x(), boundingRect().bottom()));
}

void BlockGraphicsItem::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    BlockPropertyDialog dialog(block_);

    if(dialog.exec() == QDialog::Accepted)
    {

    }
}
