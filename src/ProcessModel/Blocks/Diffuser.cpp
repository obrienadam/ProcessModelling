#include "Diffuser.h"

Diffuser::Diffuser()
    :
      Block(1, 1, 0, "Diffuser")
{

}

void Diffuser::setProperties(const std::map<std::string, double> &properties)
{

}

std::map<std::string, double> Diffuser::properties() const
{
    return {};
}

std::map<std::string, double> Diffuser::solution() const
{
    return {};
}
