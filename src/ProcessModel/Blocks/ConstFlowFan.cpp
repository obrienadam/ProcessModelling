#include "ConstFlowFan.h"
#include "Connector.h"

ConstFlowFan::ConstFlowFan()
    :
      Block(1, 1, 0, "Const Flow Fan")
{

}

void ConstFlowFan::setNodeEquations()
{
    std::shared_ptr<Node> output = outputs_.back();
    std::shared_ptr<Node> input = inputs_.back();

    Equation inputEqn;

    double r1 = input->connector().resistance();

    inputEqn.addCoeff(input->connector().sourceNode(), 1);
    inputEqn.addCoeff(input, -1);
    inputEqn.setSource(r1*Q_);

    Equation outputEqn;

    double r2 = output->connector().resistance();

    outputEqn.addCoeff(output, 1);
    outputEqn.addCoeff(output->connector().destNode(), -1);
    outputEqn.setSource(r2*Q_);

    input->setEquation(inputEqn);
    output->setEquation(outputEqn);
}

void ConstFlowFan::setProperties(const std::map<std::string, double> &properties)
{
    Q_ = properties.find("Flow rate")->second;
}

std::map<std::string, double> ConstFlowFan::properties() const
{
    return {
        {"Flow rate", Q_}
    };
}

std::map<std::string, double> ConstFlowFan::solution() const
{
    return {
        {"Pressure increase", dP_}
    };
}

void ConstFlowFan::updateSolution()
{
    double pin = inputs().back()->state()("p");
    double pout = outputs().back()->state()("p");
    dP_ = pout - pin;
}
