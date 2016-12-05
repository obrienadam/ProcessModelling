#ifndef CONNECTORGRAPHICSPATHITEM_H
#define CONNECTORGRAPHICSPATHITEM_H

#include <QGraphicsPathItem>
#include "Connector.h"
#include "NodeGraphicsItem.h"

class ConnectorGraphicsPathItem : public QGraphicsPathItem
{
public:

    enum {Type = UserType + 2};

    ConnectorGraphicsPathItem();
    ConnectorGraphicsPathItem(NodeGraphicsItem* sourceNode, NodeGraphicsItem* destNode);
    ~ConnectorGraphicsPathItem();

    int type() const override { return Type; }

    void setSourceNode(NodeGraphicsItem *sourceNode);
    void setPathTo(const QPointF& pos);
    void resetPath();

    void update(const QRectF &rect = QRectF());

    NodeGraphicsItem* sourceNode() { return sourceNode_; }
    NodeGraphicsItem* destNode() { return destNode_; }

    bool isConnected() const { return connector_; }
    Connector* connect(NodeGraphicsItem* destNode);
    void disconnect();
    Connector* connector(){ return connector_; }

private:

    void computePath(const QPointF& start, const QPointF& end);

    NodeGraphicsItem *sourceNode_, *destNode_;
    Connector *connector_;
};

#endif // ConnectorGraphicsPathItem_H