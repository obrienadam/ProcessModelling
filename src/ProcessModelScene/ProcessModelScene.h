#ifndef PROCESSMODELSCENE_H
#define PROCESSMODELSCENE_H

#include <QGraphicsScene>

#include "BlockGraphicsItem.h"
#include "NodeGraphicsItem.h"
#include "ConnectorGraphicsPathItem.h"
#include "FlowModel.h"

class ProcessModelScene : public QGraphicsScene
{

public:

    ProcessModelScene(QObject* parent = nullptr);

    ~ProcessModelScene();

    //- Add a new block
    BlockGraphicsItem *addBlock(std::shared_ptr<Block>& block,
                  const QImage& img,
                  const std::vector<QPointF> &nodePts,
                  const QPointF& scenePos);

    ConnectorGraphicsPathItem *connect(std::shared_ptr<NodeGraphicsItem>& source,
                                       std::shared_ptr<NodeGraphicsItem>& dest);

    void setFlowModel(std::shared_ptr<FlowModel>& flowModel)
    { flowModel_ = flowModel; }

    //- Get scene items
    std::vector<std::shared_ptr<Block>> getBlocks();

    std::vector<std::shared_ptr<Connector>> getConnectors();

    //- Get graphics items
    template<class T>
    std::vector<T*> getGraphicsItems()
    {
        std::vector<T*> items;

        for(QGraphicsItem* item: this->items())
            if(item->type() == T::Type)
                items.push_back(static_cast<T*>(item));

        return items;
    }

private:

    //- Various events
    void keyPressEvent(QKeyEvent *event) override;

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;

    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

    //- Template helper method for getting items
    template<class T>
    T* getItem(const QPointF& pos)
    {
        for(QGraphicsItem* item: this->items(pos))
            if(item && item->type() == T::Type)
                return static_cast<T*>(item);

        return nullptr;
    }

    //- Flow model, used to initialize newly created entities
    std::shared_ptr<FlowModel> flowModel_;

    //- Tmp for connecor
    ConnectorGraphicsPathItem *tmpConnector_;
};

#endif // PROCESSMODELSCENE_H
