#ifndef CONSTFLOWFAN_H
#define CONSTFLOWFAN_H

#include "Block.h"

class PROCESSMODELSHARED_EXPORT ConstFlowFan : public Block
{
public:
    ConstFlowFan();

    void setNodeEquations() override;
};

#endif // CONSTFLOWFAN_H
