#ifndef RESTRICTOR_VALVE_H
#define RESTRICTOR_VALVE_H

#include "Block.h"

class PROCESSMODELSHARED_EXPORT RestrictorValve : public Block
{
public:
    RestrictorValve();

    void setNodeEquations() override;
    void updateSolution() override;
private:
};

#endif // VALVE_H
