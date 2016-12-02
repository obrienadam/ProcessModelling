#ifndef CONNECTORGRAPHICSPATHOBJECT_H
#define CONNECTORGRAPHICSPATHOBJECT_H

#include <QGraphicsPathItem>
#include "Connector.h"

class NodeGraphicsObject;

class ConnectorGraphicsPathObject : public QGraphicsPathItem
{
public:

    enum {Type = UserType + 2};

    int type() const { return Type; }

    ConnectorGraphicsPathObject();
    ~ConnectorGraphicsPathObject();

    void setPath(NodeGraphicsObject* node, const QPointF &scenePos);
    void setPath();

    bool connect(NodeGraphicsObject *sourceNode, NodeGraphicsObject *destNode);
    void disconnect();

    Connector* connector() { return connector_; }

    NodeGraphicsObject* sourceNode() { return sourceNode_; }
    NodeGraphicsObject* destNode() { return destNode_; }

private:

    void computePath(const QPointF& start, const QPointF& end);

    Connector *connector_;
    NodeGraphicsObject* sourceNode_ = nullptr, *destNode_ = nullptr;
};

#endif // CONNECTORGRAPHICSPATHOBJECT_H
