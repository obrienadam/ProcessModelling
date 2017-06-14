#ifndef DIFFUSER_H
#define DIFFUSER_H

#include "Block.h"

class PROCESSMODELSHARED_EXPORT Diffuser : public Block
{
public:
    Diffuser();

    std::string type() const
    { return "Diffuser"; }

    //- Properties
    void setProperties(const std::map<std::string, double>& properties);

    std::map<std::string, double> properties() const;

    //- Solution
    std::map<std::string, double> solution() const;
};

#endif // DIFFUSER_H
