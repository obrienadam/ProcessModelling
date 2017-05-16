#ifndef CONSTFLOWFAN_H
#define CONSTFLOWFAN_H

#include "Block.h"

class PROCESSMODELSHARED_EXPORT ConstFlowFan : public Block
{
public:
    ConstFlowFan();

    std::string type() const
    { return "Constant Flow Fan"; }

    void setNodeEquations() override;
    void updateSolution() override;
};

#endif // CONSTFLOWFAN_H
