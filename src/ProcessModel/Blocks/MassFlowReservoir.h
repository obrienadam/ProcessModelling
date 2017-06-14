#ifndef MASSFLOWRESERVOIR_H
#define MASSFLOWRESERVOIR_H

#include "Block.h"

class PROCESSMODELSHARED_EXPORT MassFlowReservoir : public Block
{
public:
    MassFlowReservoir();

    std::string type() const
    { return "Mass Flow Reservoir"; }

    //- Properties
    void setProperties(const std::map<std::string, double>& properties);

    std::map<std::string, double> properties() const;

    //- Solution
    std::map<std::string, double> solution() const;

    void setNodeEquations() override;

private:
    double Q_; //- properties
};

#endif // MASSFLOWRESERVOIR_H
