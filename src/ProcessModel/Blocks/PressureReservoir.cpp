#include "PressureReservoir.h"

PressureReservoir::PressureReservoir()
    :
      Block(0, 0, 1, "Const Pressure")
{

}

void PressureReservoir::setProperties(const std::map<std::string, double> &properties)
{
    p_ = properties.find("Pressure")->second;
}

std::map<std::string, double> PressureReservoir::properties() const
{
    return {
        {"Pressure", p_}
    };
}

std::map<std::string, double> PressureReservoir::solution() const
{
    return {};
}

void PressureReservoir::setNodeEquations()
{
    std::shared_ptr<Node> node = sinks_.back();
    Equation eqn;

    eqn.addCoeff(node, 1.);
    eqn.setSource(p_);
    node->setEquation(eqn);
}
