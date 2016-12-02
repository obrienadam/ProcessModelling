#include <QPainter>
#include <QTextDocument>
#include <QGraphicsSceneMouseEvent>
#include <QStyleOptionGraphicsItem>
#include <QDebug>

#include "BlockGraphicsObject.h"

BlockGraphicsObject::BlockGraphicsObject(Block *block)
    :
      QGraphicsRectItem(0, 0, 50, 50)
{
    setFlags(ItemIsMovable|ItemIsSelectable|ItemSendsGeometryChanges);
    setAcceptedMouseButtons(Qt::LeftButton);

    setPen(QPen(Qt::black, 2));
    setBrush(QBrush(Qt::white));

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

void BlockGraphicsObject::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(text_->document()->isModified())
    {
        block_->name = text_->toPlainText().toStdString();
        setTextPosition();
        qDebug() << "Repositioned text.";
    }

    QGraphicsRectItem::paint(painter, option, widget);
}

void BlockGraphicsObject::setNodes()
{   
    QPointF points[] = {QPointF(-10, 20), QPointF(50, 20), QPointF(20, 50), QPointF(20, -10)};
    int n = 0;

    for(Node* node: *block())
    {
        nodes_.push_back(new NodeGraphicsObject(node, this));
        nodes_.back()->setPos(points[n++]);
    }
}

void BlockGraphicsObject::setText()
{
    text_ = new QGraphicsTextItem(this);
    text_->setPlainText(block_->name.c_str());
    text_->setTextInteractionFlags(Qt::TextEditable|Qt::TextSelectableByKeyboard);
    text_->setFlag(QGraphicsItem::ItemIgnoresTransformations);
    setTextPosition();
}

void BlockGraphicsObject::setTextPosition()
{
    qreal textHalfWidth = text_->boundingRect().width()/2.;
    text_->setPos(
                boundingRect().center().x() - textHalfWidth,
                50.
                );
}
