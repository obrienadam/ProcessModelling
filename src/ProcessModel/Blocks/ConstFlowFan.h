#ifndef CONSTFLOWFAN_H
#define CONSTFLOWFAN_H

#include "Block.h"

class PROCESSMODELSHARED_EXPORT ConstFlowFan : public Block
{
public:
    ConstFlowFan();

    std::string type() const
    { return "Constant Flow Fan"; }

    void setNodeEquations() override;

    //- Properties
    void setProperties(const std::map<std::string, double>& properties);

    std::map<std::string, double> properties() const;

    //- Solution
    std::map<std::string, double> solution() const;

    void updateSolution();

private:
    double Q_; //- Flow rate
    double dP_; //- Pressure change
};

#endif // CONSTFLOWFAN_H
