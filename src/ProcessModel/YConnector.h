#ifndef Y_CONNECTOR_H
#define Y_CONNECTOR_H

#include "Block.h"

class YConnector: public Block
{
public:
    YConnector();

    void setNodeEquations() override;
    void updateSolution() override;
};

#endif
