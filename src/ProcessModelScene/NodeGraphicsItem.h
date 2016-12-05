#ifndef NODEGRAPHICSITEM_H
#define NODEGRAPHICSITEM_H

#include <memory>
#include <QGraphicsEllipseItem>

#include "Node.h"

class BlockGraphicsItem;
class ConnectorGraphicsPathItem;

class NodeGraphicsItem : public QGraphicsEllipseItem
{
public:

    enum {Type = UserType + 3};

    //- Constructors
    NodeGraphicsItem(Node* node, BlockGraphicsItem* block);
    ~NodeGraphicsItem();

    //- Qt methods
    int type() const override { return Type; }
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    //- Misc
    void addConnection(ConnectorGraphicsPathItem* connector) { connector_ = connector; }
    void removeConnection();
    Node* node();
    bool isConnected() const { return connector_ != nullptr; }

private:

    //- Note: NodeGraphicsItem does not assume ownership over node_
    Node* node_;
    ConnectorGraphicsPathItem *connector_;
};

#endif // NODEGRAPHICSItem_H
