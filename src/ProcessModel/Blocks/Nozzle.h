#ifndef NOZZLE_H
#define NOZZLE_H

#include "Block.h"

class PROCESSMODELSHARED_EXPORT Nozzle : public Block
{
public:
    Nozzle();

    std::string type() const
    { return "Nozzle"; }

    //- Properties
    void setProperties(const std::map<std::string, double>& properties);

    std::map<std::string, double> properties() const;

    //- Solution
    std::map<std::string, double> solution() const;
};

#endif // NOZZLE_H
