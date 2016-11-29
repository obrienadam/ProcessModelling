#include <QPainter>
#include <QTextDocument>

#include "BlockGraphicsObject.h"

BlockGraphicsObject::BlockGraphicsObject(Block *block)
{
    setFlags(ItemIsMovable|ItemIsSelectable);
    block_ = block;
    setNodes();
    setText();
}

BlockGraphicsObject::~BlockGraphicsObject()
{
    delete text_;
    for(QGraphicsItem *node: nodes_)
        delete node;
}

QRectF BlockGraphicsObject::boundingRect() const
{
    return QRectF(0, 0, 50, 50);
}

void BlockGraphicsObject::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPen pen(Qt::black, 2);
    QBrush brush(Qt::white);

    painter->setPen(pen);
    painter->setBrush(brush);
    painter->drawRect(boundingRect());

    if(text_->document()->isModified())
    {
        setTextPosition();
        block_->name = text_->toPlainText().toStdString();
    }
}

void BlockGraphicsObject::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{

}

void BlockGraphicsObject::setNodes()
{
    QGraphicsEllipseItem *node = new QGraphicsEllipseItem(50, 20, 10, 10, this);
    node->setPen(QPen(Qt::black, 2));
    node->setBrush(QBrush(Qt::blue));
    nodes_.push_back(node);
}

void BlockGraphicsObject::setText()
{
    text_ = new QGraphicsTextItem(this);
    text_->setPlainText(block_->name.c_str());
    text_->setTextInteractionFlags(Qt::TextEditable|Qt::TextSelectableByKeyboard);
    setTextPosition();
}

void BlockGraphicsObject::setTextPosition()
{
    qreal centerText = text_->boundingRect().center().x();
    qreal centerComp = boundingRect().center().x();

    text_->setPos(
                centerComp - centerText,
                50
                );
}
