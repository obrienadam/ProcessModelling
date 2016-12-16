#ifndef TJUNCTION_H
#define TJUNCTION_H

#include "Block.h"

class TJunction : public Block
{
public:
    TJunction();

    void setNodeEquations() override;
};

#endif // TJUNCTION_H
