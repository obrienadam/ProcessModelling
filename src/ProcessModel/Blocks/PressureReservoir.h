#ifndef PRESSURERESERVOIR_H
#define PRESSURERESERVOIR_H

#include "processmodel_global.h"
#include "Block.h"

class PROCESSMODELSHARED_EXPORT PressureReservoir : public Block
{
public:
    PressureReservoir();

    std::string type() const
    { return "Pressure Reservoir"; }

    void setNodeEquations();
};

#endif // PRESSURERESERVOIR_H
