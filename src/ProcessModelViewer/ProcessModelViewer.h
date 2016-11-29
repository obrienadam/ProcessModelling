#ifndef PROCESSMODELVIEWER_H
#define PROCESSMODELVIEWER_H

#include <QGraphicsScene>

#include "processmodelviewer_global.h"
#include "processmodel.h"
#include "BlockGraphicsObject.h"

class PROCESSMODELVIEWERSHARED_EXPORT ProcessModelViewer : public QGraphicsScene
{

public:

    ProcessModelViewer();
    ~ProcessModelViewer();

    void addBlock(BlockGraphicsObject* block);

private:

    ProcessModel processModel_;
    std::vector<BlockGraphicsObject*> blocks_;
};

#endif // PROCESSMODELVIEWER_H
