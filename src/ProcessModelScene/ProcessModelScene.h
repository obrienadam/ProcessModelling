#ifndef PROCESSMODELSCENE_H
#define PROCESSMODELSCENE_H

#include <QGraphicsScene>

#include "BlockGraphicsItem.h"
#include "NodeGraphicsItem.h"
#include "ConnectorGraphicsPathItem.h"

class ProcessModelScene : public QGraphicsScene
{

public:

    ProcessModelScene(QObject* parent = nullptr);
    ~ProcessModelScene();

    void addBlock(Block* block, const QImage& img, const QPointF& scenePos);

private:

    void keyPressEvent(QKeyEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

    BlockGraphicsItem *blockAt(const QPointF& scenePos);
    ConnectorGraphicsPathItem *connectorAt(const QPointF& scenePos);
    NodeGraphicsItem *nodeAt(const QPointF& scenePos);

    //- Tmp for connecor
    ConnectorGraphicsPathItem *tmpConnector_;
};

#endif // PROCESSMODELSCENE_H