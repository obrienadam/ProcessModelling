#ifndef RESTRICTOR_VALVE_H
#define RESTRICTOR_VALVE_H

#include "Block.h"

class PROCESSMODELSHARED_EXPORT RestrictorValve : public Block
{
public:
    RestrictorValve();

    std::string type() const
    { return "Restrictor Valve"; }

    //- Properties
    void setProperties(const std::map<std::string, double>& properties);

    std::map<std::string, double> properties() const;

    //- Solution
    std::map<std::string, double> solution() const;

    void updateSolution() override;

    void setNodeEquations() override;

    void setQmax(double Qmax)
    { Qmax_ = Qmax; }

    double Q() const
    { return Q_; }

    double Qmax() const
    { return Qmax_; }

private:
    double Qmax_, rMin_; //- properties
    double r_, dP_, Q_; //- Solution
};

#endif // VALVE_H
