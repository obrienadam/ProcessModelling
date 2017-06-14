#include <QPainter>
#include <QTextDocument>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QStyleOptionGraphicsItem>

#include "BlockGraphicsItem.h"
#include "PropertyDialog.h"

BlockGraphicsItem::BlockGraphicsItem(std::shared_ptr<Block>& block,
                                     const QImage &img,
                                     const std::vector<QPointF> &nodePts)
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
        nodes_.push_back(std::shared_ptr<NodeGraphicsItem>(new NodeGraphicsItem(node, this)));
        nodes_.back()->setPos(nodePts[i++]);
    }
}

BlockGraphicsItem::~BlockGraphicsItem()
{
    if(scene())
        scene()->removeItem(this);
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

void BlockGraphicsItem::setName(const std::string &name)
{
    block_->name = name;
    setText();
}

void BlockGraphicsItem::flipHorizontal()
{
    if(transform().isScaling())
        setTransform(QTransform::fromScale(1, 1));
    else
        setTransform(QTransform::fromScale(-1, 1));
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
    PropertyDialog dialog(block_->name + " Properties",
                          "Block Type: " + block_->type(),
                          block_->properties(),
                          block_->solution());

    if(dialog.exec() == QDialog::Accepted)
        block_->setProperties(dialog.properties());
}
