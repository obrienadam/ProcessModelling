#include "MassFlowReservoir.h"
#include "Connector.h"

MassFlowReservoir::MassFlowReservoir()
    :
      Block(0, 0, 1, "Mass Flow Reservoir", "Q")
{
    addProperty("Flow rate", "Q", 0, -10000, 10000);
}

void MassFlowReservoir::setNodeEquations()
{
    Node* node = nodes_.back().get();

    double r = node->connector().getResistance();
    Equation eqn;

    eqn.addCoeff(node, 1./r);
    eqn.addCoeff(node->connector().destNode(), -1./r);
    eqn.setSource(properties_.find("Flow rate")->second.value);

    node->setEquation(eqn);
}
