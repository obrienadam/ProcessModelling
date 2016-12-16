#include "PressureReservoir.h"

PressureReservoir::PressureReservoir()
    :
      Block(0, 0, 1, "Pressure Reservoir", "Patm")
{
    addProperty("Pressure", "P", 101325., 0, 2*101325);
}

void PressureReservoir::setNodeEquations()
{
    Node *node = sinks_.back().get();
    Equation eqn;

    eqn.addCoeff(node, 1.);
    eqn.setSource(properties_["Pressure"].value);
    node->setEquation(eqn);
}
