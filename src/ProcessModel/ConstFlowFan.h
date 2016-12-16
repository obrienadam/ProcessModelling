#ifndef CONSTFLOWFAN_H
#define CONSTFLOWFAN_H

#include "Block.h"

class ConstFlowFan : public Block
{
public:
    ConstFlowFan();

    void setNodeEquations() override;
};

#endif // CONSTFLOWFAN_H
