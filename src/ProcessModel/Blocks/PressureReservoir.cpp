#include "PressureReservoir.h"

PressureReservoir::PressureReservoir()
    :
      Block(0, 0, 1, "Const Pressure")
{
    addProperty(Property("P", "Pressure", 0, -100, 100, Unit("Pa")));
}

void PressureReservoir::setNodeEquations()
{
    Node *node = sinks_.back().get();
    Equation eqn;

    eqn.addCoeff(node, 1.);
    eqn.setSource(getProperty("P"));
    node->setEquation(eqn);
}
