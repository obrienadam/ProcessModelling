#include "MassFlowReservoir.h"
#include "Connector.h"

MassFlowReservoir::MassFlowReservoir()
    :
      Block(0, 0, 1, "Mass Flow Reservoir", "Q")
{
    addProperty(Property("Q", "Flow rate", 0, -10000, 10000, Unit("m^3/s")));
}

void MassFlowReservoir::setNodeEquations()
{
    Node* node = nodes_.back().get();

    double r = node->connector().getResistance();
    Equation eqn;

    eqn.addCoeff(node, 1.);
    eqn.addCoeff(node->connector().destNode(), -1.);
    eqn.setSource(r*properties_.find("Q")->second.value);

    node->setEquation(eqn);
}
