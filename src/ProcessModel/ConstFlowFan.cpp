#include "ConstFlowFan.h"
#include "Connector.h"

ConstFlowFan::ConstFlowFan()
    :
      Block(1, 1, 0, "Constant Flow Fan", "Q Fan")
{
    addProperty("Flow rate", "Q", 0.01, 0.01, 1e12);
}

void ConstFlowFan::setNodeEquations()
{
    Node* output = outputs_.back().get();
    Node* input = inputs_.back().get();
    double Q = properties().find("Flow rate")->second.value;

    Equation inputEqn;

    double r1 = input->connector().getResistance();

    inputEqn.addCoeff(input->connector().sourceNode(), 1/r1);
    inputEqn.addCoeff(input, -1/r1);
    inputEqn.setSource(Q);

    Equation outputEqn;

    double r2 = output->connector().getResistance();

    outputEqn.addCoeff(output, 1/r2);
    outputEqn.addCoeff(output->connector().destNode(), -1/r2);
    outputEqn.setSource(Q);

    input->setEquation(inputEqn);
    output->setEquation(outputEqn);
}
