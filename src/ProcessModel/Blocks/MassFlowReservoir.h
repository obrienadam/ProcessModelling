#ifndef MASSFLOWRESERVOIR_H
#define MASSFLOWRESERVOIR_H

#include "Block.h"

class PROCESSMODELSHARED_EXPORT MassFlowReservoir : public Block
{
public:
    MassFlowReservoir();

    std::string type() const
    { return "Mass Flow Reservoir"; }

    void setNodeEquations() override;
};

#endif // MASSFLOWRESERVOIR_H
