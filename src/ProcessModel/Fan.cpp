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

    Equation outputEqn;
    outputEqn.addCoeff(output, 1.);
    outputEqn.addCoeff(input, -properties_["Pressure ratio"].value);

    output->setEquation(outputEqn);

    Equation inputEquation;

    double r1 = input->connector().getResistance();
    double r2 = output->connector().getResistance();

    inputEquation.addCoeff(input->connector().sourceNode(), 1/r1);
    inputEquation.addCoeff(input, -1/r1);
    inputEquation.addCoeff(output, 1/r2);
    inputEquation.addCoeff(output->connector().destNode(), -1/r2);

    input->setEquation(inputEquation);
}
