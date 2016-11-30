#ifndef CONNECTORGRAPHICSPATHOBJECT_H
#define CONNECTORGRAPHICSPATHOBJECT_H

#include <QGraphicsPathItem>
#include "Connector.h"

class NodeGraphicsObject;

class ConnectorGraphicsPathObject : public QGraphicsPathItem
{
public:
    ConnectorGraphicsPathObject();

    void setPath(NodeGraphicsObject* node, const QPointF &scenePos);
    void connectNodes(NodeGraphicsObject *startNode, NodeGraphicsObject *endNode);

private:

    void computePath(const QPointF& start, const QPointF& end);

    Connector *connector_;
};

#endif // CONNECTORGRAPHICSPATHOBJECT_H
