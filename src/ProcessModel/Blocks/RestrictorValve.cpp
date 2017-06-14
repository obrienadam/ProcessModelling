#include "RestrictorValve.h"
#include "Connector.h"

RestrictorValve::RestrictorValve()
    :
      Block(0, 0, 2, "R-Valve")
{

}

void RestrictorValve::setProperties(const std::map<std::string, double> &properties)
{
    Qmax_ = properties.find("Max flow rate")->second;
    rMin_ = properties.find("Minimum resistance")->second;
}

std::map<std::string, double> RestrictorValve::properties() const
{
    return {
        {"Max flow rate", Qmax_},
        {"Minimum resistance", rMin_}
    };
}

std::map<std::string, double> RestrictorValve::solution() const
{
    return {
        {"Resistance", r_},
        {"Pressure drop", dP_},
        {"Flow rate", Q_}
    };
}

void RestrictorValve::updateSolution()
{
    Q_ = nodes_[1]->connector().state()("Q");
}

void RestrictorValve::setNodeEquations()
{
    double p1 = nodes_[0]->connector().otherNode(nodes_[0])->state()("p");
    double p2 = nodes_[0]->state()("p");
    double p3 = nodes_[1]->state()("p");
    double p4 = nodes_[1]->connector().otherNode(nodes_[1])->state()("p");

    double r1 = nodes_[0]->connector().resistance();
    double r2 = nodes_[1]->connector().resistance();

    //- Probe to see what the pressure drop across the entire line is

    r_ = std::max(fabs(p1 - p4)/Qmax_ - r1 - r2, rMin_);
    dP_ = p2 - p3;

    Equation eqn1, eqn2;

    if(r_ != 0.)
    {
        //- Continuity 1
        eqn1.addCoeff(nodes_[0], r_);
        eqn1.addCoeff(nodes_[0]->connector().otherNode(nodes_[0]), -r_);

        eqn1.addCoeff(nodes_[0], r1);
        eqn1.addCoeff(nodes_[1], -r1);

        //- Continuity 2
        eqn2.addCoeff(nodes_[1], r_);
        eqn2.addCoeff(nodes_[1]->connector().otherNode(nodes_[1]), -r_);

        eqn2.addCoeff(nodes_[1], r2);
        eqn2.addCoeff(nodes_[0], -r2);
    }
    else
    {
        //- Continuity
        eqn1.addCoeff(nodes_[0], 1/r1);
        eqn1.addCoeff(nodes_[0]->connector().otherNode(nodes_[0]), -1/r1);

        eqn1.addCoeff(nodes_[1], 1/r2);
        eqn1.addCoeff(nodes_[1]->connector().otherNode(nodes_[1]), -1/r2);

        //- Equal inlet/outlet pressures
        eqn2.addCoeff(nodes_[0], 1);
        eqn2.addCoeff(nodes_[1], -1);
    }

    nodes_[0]->setEquation(eqn1);
    nodes_[1]->setEquation(eqn2);
}
