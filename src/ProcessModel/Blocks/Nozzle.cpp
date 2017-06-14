#include "Nozzle.h"

Nozzle::Nozzle()
    :
      Block(1, 1, 0, "Nozzle")
{

}

void Nozzle::setProperties(const std::map<std::string, double> &properties)
{

}

std::map<std::string, double> Nozzle::properties() const
{
    return {};
}

std::map<std::string, double> Nozzle::solution() const
{
    return {};
}
