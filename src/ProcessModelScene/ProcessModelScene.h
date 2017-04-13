#ifndef PROCESSMODELSCENE_H
#define PROCESSMODELSCENE_H

#include <QGraphicsScene>

#include "BlockGraphicsItem.h"
#include "NodeGraphicsItem.h"
#include "ConnectorGraphicsPathItem.h"
#include "Model.h"

class ProcessModelScene : public QGraphicsScene
{

public:

    ProcessModelScene(QObject* parent = nullptr);
    ~ProcessModelScene();

    void addBlock(Block* block, const QImage& img, const std::vector<QPointF> &nodePts, const QPointF& scenePos);
    std::vector<Block*> getBlocks();
    std::vector<Connector*> getConnectors();

    //- Models
    void setNewModel(const std::shared_ptr<Model> &model);
    Model& model() { return *model_; }

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

    //- Active model
    std::shared_ptr<Model> model_;
};

#endif // PROCESSMODELSCENE_H
