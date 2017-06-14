#ifndef FAN_H
#define FAN_H

#include "processmodel_global.h"
#include "Block.h"

class PROCESSMODELSHARED_EXPORT Fan : public Block
{
public:
    Fan();

    std::string type() const
    { return "Fan"; }

    //- Properties
    void setProperties(const std::map<std::string, double>& properties);

    std::map<std::string, double> properties() const;

    //- Solution
    std::map<std::string, double> solution() const;

    void setNodeEquations() override;

    double pressureIncrease() const
    { return dP_; }

    void setPressureIncrease(double dP)
    { dP_ = dP; }

private:
    double dP_; //- properties
};

#endif // FAN_H
