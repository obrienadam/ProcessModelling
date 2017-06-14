#ifndef Y_CONNECTOR_H
#define Y_CONNECTOR_H

#include "Block.h"

class YConnector: public Block
{
public:
    YConnector();

    std::string type() const
    { return "Y Connector"; }

    //- Properties
    void setProperties(const std::map<std::string, double>& properties);

    std::map<std::string, double> properties() const;

    //- Solution
    std::map<std::string, double> solution() const;

    void updateSolution() override;

    void setNodeEquations() override;

private:
    double Kre_, Kloss_; //- properties
    double vEntA_, vEntB_, vExit_; //- solution
};

#endif
