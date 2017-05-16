#ifndef NOZZLE_H
#define NOZZLE_H

#include "Block.h"

class PROCESSMODELSHARED_EXPORT Nozzle : public Block
{
public:
    Nozzle();

    std::string type() const
    { return "Nozzle"; }
};

#endif // NOZZLE_H
