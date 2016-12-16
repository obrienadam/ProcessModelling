#include "Fan.h"
#include "Connector.h"

Fan::Fan()
    :
      Block(1, 1, 0, "Fan", "Fan")
{
    addProperty("Pressure ratio", "PI", 1., 0., 10.);
}

void Fan::setNodeEquations()
{
    Node* output = outputs_.back().get();
    Node* input = inputs_.back().get();

    Equation inputEqn;

    double r1 = input->connector().getResistance();
    inputEqn.addCoeff(input->connector().sourceNode(), 1/r1);
    inputEqn.addCoeff(input, -1/r1);

    double r2 = output->connector().getResistance();
    inputEqn.addCoeff(output, -1/r2);
    inputEqn.addCoeff(output->connector().destNode(), 1/r2);

    Equation outputEqn;
    outputEqn.addCoeff(output, 1.);
    outputEqn.addCoeff(input, -properties_["Pressure ratio"].value);

    input->setEquation(inputEqn);
    output->setEquation(outputEqn);
}
