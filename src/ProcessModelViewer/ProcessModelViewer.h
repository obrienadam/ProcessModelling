#ifndef PROCESSMODELVIEWER_H
#define PROCESSMODELVIEWER_H

#include <QGraphicsScene>

#include "processmodelviewer_global.h"
#include "ProcessModel.h"
#include "BlockGraphicsObject.h"

class PROCESSMODELVIEWERSHARED_EXPORT ProcessModelViewer : public QGraphicsScene
{

public:

    ProcessModelViewer();
    ~ProcessModelViewer();

    void addBlock(BlockGraphicsObject* block);

private:

    void keyPressEvent(QKeyEvent *event) override;
    void deleteBlock(BlockGraphicsObject *block);
    void deleteConnector(ConnectorGraphicsPathObject *connector);

    ProcessModel processModel_;
    std::vector<BlockGraphicsObject*> blocks_;
};

#endif // PROCESSMODELVIEWER_H
