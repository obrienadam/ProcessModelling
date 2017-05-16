#ifndef PGMODEL_H
#define PGMODEL_H

#include "Model.h"

class PROCESSMODELSHARED_EXPORT PGModel : public Model
{
public:
    PGModel();

    const std::string type() const { return "P&G"; }
};

#endif // PGMODEL_H
