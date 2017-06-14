#include "Fan.h"
#include "Connector.h"

Fan::Fan()
    :
      Block(1, 1, 0, "Fan")
{

}

void Fan::setProperties(const std::map<std::string, double> &properties)
{
    dP_ = properties.find("Pressure increase")->second;
}

std::map<std::string, double> Fan::properties() const
{
    return {
        {"Pressure increase", dP_}
    };
}

std::map<std::string, double> Fan::solution() const
{
    return {};
}

void Fan::setNodeEquations()
{
    std::shared_ptr<Node> output = outputs_.back();
    std::shared_ptr<Node> input = inputs_.back();

    Equation inputEqn;

    double r1 = input->connector().resistance();
    double r2 = output->connector().resistance();

    inputEqn.addCoeff(input->connector().sourceNode(), r2);
    inputEqn.addCoeff(input, -r2);

    inputEqn.addCoeff(output, -r1);
    inputEqn.addCoeff(output->connector().destNode(), r1);

    Equation outputEqn;
    outputEqn.addCoeff(output, 1.);
    outputEqn.addCoeff(input, -1.);
    outputEqn.setSource(dP_);

    input->setEquation(inputEqn);
    output->setEquation(outputEqn);
}
