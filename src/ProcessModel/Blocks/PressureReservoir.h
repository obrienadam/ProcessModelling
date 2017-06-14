#ifndef PRESSURERESERVOIR_H
#define PRESSURERESERVOIR_H

#include "processmodel_global.h"
#include "Block.h"

class PROCESSMODELSHARED_EXPORT PressureReservoir : public Block
{
public:
    PressureReservoir();

    std::string type() const
    { return "Pressure Reservoir"; }

    //- Properties
    void setProperties(const std::map<std::string, double>& properties);

    std::map<std::string, double> properties() const;

    //- Solution
    std::map<std::string, double> solution() const;

    void setNodeEquations();

private:
    double p_; //- properties
};

#endif // PRESSURERESERVOIR_H
