#ifndef Y_CONNECTOR_H
#define Y_CONNECTOR_H

#include "Block.h"

class YConnector: public Block
{
public:
    YConnector();

    std::string type() const
    { return "Y Connector"; }

    void setNodeEquations() override;
    void updateSolution() override;
};

#endif
