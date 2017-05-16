#include "Fan.h"
#include "Connector.h"

Fan::Fan()
    :
      Block(1, 1, 0, "Fan")
{
    addProperty(Property("dP", "Pressure increase", 0.1, 0., 1e12, Unit("Pa")));
}

void Fan::setNodeEquations()
{
    Node* output = outputs_.back().get();
    Node* input = inputs_.back().get();

    Equation inputEqn;

    double r1 = input->connector().getResistance();
    double r2 = output->connector().getResistance();

    inputEqn.addCoeff(input->connector().sourceNode(), r2);
    inputEqn.addCoeff(input, -r2);

    inputEqn.addCoeff(output, -r1);
    inputEqn.addCoeff(output->connector().destNode(), r1);

    Equation outputEqn;
    outputEqn.addCoeff(output, 1.);
    outputEqn.addCoeff(input, -1.);
    outputEqn.setSource(properties().find("dP")->second.value);

    input->setEquation(inputEqn);
    output->setEquation(outputEqn);
}
