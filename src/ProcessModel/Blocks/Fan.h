#ifndef FAN_H
#define FAN_H

#include "processmodel_global.h"
#include "Block.h"

class PROCESSMODELSHARED_EXPORT Fan : public Block
{
public:
    Fan();

    void setNodeEquations() override;
};

#endif // FAN_H
