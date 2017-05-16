#ifndef MASSFLOWRESERVOIR_H
#define MASSFLOWRESERVOIR_H

#include "Block.h"

class PROCESSMODELSHARED_EXPORT MassFlowReservoir : public Block
{
public:
    MassFlowReservoir();

    void setNodeEquations() override;
};

#endif // MASSFLOWRESERVOIR_H
