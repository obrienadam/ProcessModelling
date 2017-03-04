#include "ConstFlowFan.h"
#include "Connector.h"

ConstFlowFan::ConstFlowFan()
    :
      Block(1, 1, 0, "Constant Flow Fan", "Q Fan")
{
    addProperty(Property("Flow rate", "Q", 0.01, 0.01, 1e12, Unit("m^3/s", 1.)));
    solution_["Pressure difference"] = Property("Pressure difference", "dp");
    solution_["Power"] = Property("Power", "W");
}

void ConstFlowFan::setNodeEquations()
{
    Node* output = outputs_.back().get();
    Node* input = inputs_.back().get();
    double Q = properties().find("Flow rate")->second.value;

    Equation inputEqn;

    double r1 = input->connector().getResistance();

    inputEqn.addCoeff(input->connector().sourceNode(), 1);
    inputEqn.addCoeff(input, -1);
    inputEqn.setSource(r1*Q);

    Equation outputEqn;

    double r2 = output->connector().getResistance();

    outputEqn.addCoeff(output, 1);
    outputEqn.addCoeff(output->connector().destNode(), -1);
    outputEqn.setSource(r2*Q);

    input->setEquation(inputEqn);
    output->setEquation(outputEqn);
}

void ConstFlowFan::updateSolution()
{
    double pin = inputs().back()->getSolutionVariable("Pressure");
    double pout = outputs().back()->getSolutionVariable("Pressure");
    double Q = outputs().back()->connector().getSolutionVariable("Flow rate");
    setSolution("Pressure difference", pout - pin);
    setSolution("Power", (pout - pin)*Q);
}
