#ifndef TJUNCTION_H
#define TJUNCTION_H

#include "Block.h"

class PROCESSMODELSHARED_EXPORT TJunction : public Block
{
public:
    TJunction();

    void setNodeEquations() override;
};

#endif // TJUNCTION_H
