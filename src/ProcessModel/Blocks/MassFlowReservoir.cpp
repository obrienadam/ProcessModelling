#include "MassFlowReservoir.h"
#include "Connector.h"

MassFlowReservoir::MassFlowReservoir()
    :
      Block(0, 0, 1, "Const Flow")
{

}

void MassFlowReservoir::setProperties(const std::map<std::string, double> &properties)
{
    Q_ = properties.find("Flow rate")->second;
}

std::map<std::string, double> MassFlowReservoir::properties() const
{
    return {
        {"Flow rate", Q_}
    };
}

std::map<std::string, double> MassFlowReservoir::solution() const
{
    return {};
}

void MassFlowReservoir::setNodeEquations()
{
    std::shared_ptr<Node> node = nodes_.back();

    double r = node->connector().resistance();
    Equation eqn;

    eqn.addCoeff(node, 1.);
    eqn.addCoeff(node->connector().destNode(), -1.);
    eqn.setSource(r*Q_);

    node->setEquation(eqn);
}
