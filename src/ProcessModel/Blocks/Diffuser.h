#ifndef DIFFUSER_H
#define DIFFUSER_H

#include "Block.h"

class PROCESSMODELSHARED_EXPORT Diffuser : public Block
{
public:
    Diffuser();

    std::string type() const
    { return "Diffuser"; }
};

#endif // DIFFUSER_H
