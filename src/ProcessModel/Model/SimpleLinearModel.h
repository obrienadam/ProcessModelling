#ifndef SIMPLELINEARMODEL_H
#define SIMPLELINEARMODEL_H

#include "Model.h"

class PROCESSMODELSHARED_EXPORT SimpleLinearModel: public Model
{
public:
    SimpleLinearModel();

    const std::string type() const { return "Simple Linear"; }
};

#endif // SIMPLELINEARMODEL_H
