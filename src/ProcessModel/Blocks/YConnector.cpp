#include "YConnector.h"
#include "Connector.h"

YConnector::YConnector()
    :
      Block(2, 1, 0, "Y-Connector")
{

}

void YConnector::setProperties(const std::map<std::string, double> &properties)
{
    Kre_ = properties.find("Regain coefficient")->second;
    Kloss_ = properties.find("Loss coefficient")->second;
}

std::map<std::string, double> YConnector::properties() const
{
    return {
        {"Regain coefficient", Kre_},
        {"Loss coefficient", Kloss_}
    };
}

std::map<std::string, double> YConnector::solution() const
{
    return {
        {"Entrance velocity A", vEntA_},
        {"Entrance velocity B", vEntB_},
        {"Exit velocity", vExit_}
    };
}

void YConnector::updateSolution()
{
    Connector& c1 = inputs_[0]->connector(),
            &c2 = inputs_[1]->connector(),
            &c3 = outputs_[0]->connector();

    double d1, d2, d3;

    d1 = c1.state()("D");
    d2 = c2.state()("D");
    d3 = c3.state()("D");

    double a1, a2, a3;

    a1 = M_PI*d1*d1/4./144.;
    a2 = M_PI*d2*d2/4./144.;
    a3 = M_PI*d3*d3/4./144.;

    double q1, q2, q3;

    q1 = c1.state()("Q");
    q2 = c2.state()("Q");
    q3 = c3.state()("Q");

    double v1, v2, v3;

    v1 = q1/a1;
    v2 = q2/a2;
    v3 = q3/a3;

    vEntA_ = v1;
    vEntB_ = v2;
    vExit_ = v3;
}

void YConnector::setNodeEquations()
{
    double r1, r2, r3;
    Equation eqn1, eqn2, eqn3;

    Connector& c1 = inputs_[0]->connector(),
            &c2 = inputs_[1]->connector(),
            &c3 = outputs_[0]->connector();

    r1 = c1.resistance();
    r2 = c2.resistance();
    r3 = c3.resistance();

    //- Continuity equation
    eqn1.addCoeff(c1.otherNode(inputs_[0]), 1/r1);
    eqn1.addCoeff(inputs_[0], -1/r1);

    eqn1.addCoeff(c2.otherNode(inputs_[1]), 1/r2);
    eqn1.addCoeff(inputs_[1], -1/r2);

    eqn1.addCoeff(c3.otherNode(outputs_[0]), 1/r3);
    eqn1.addCoeff(outputs_[0], -1/r3);

    //- Static regain/losses

    double d1, d2, d3;

    d1 = c1.state()("D");
    d2 = c2.state()("D");
    d3 = c3.state()("D");

    double a1, a2, a3;

    a1 = M_PI*d1*d1/4./144.;
    a2 = M_PI*d2*d2/4./144.;
    a3 = M_PI*d3*d3/4./144.;

    double q1, q2, q3;

    q1 = c1.state()("Q");
    q2 = c2.state()("Q");
    q3 = c3.state()("Q");

    double v1, v2, v3;

    v1 = q1/a1;
    v2 = q2/a2;
    v3 = q3/a3;

    double vp1, vp2, vp3;

    vp1 = v1*v1/(4005*4005);
    vp2 = v2*v2/(4005*4005);
    vp3 = v3*v3/(4005*4005);

    eqn2.addCoeff(outputs_[0], 1);
    eqn2.addCoeff(inputs_[0], -1);

    eqn3.addCoeff(outputs_[0], 1);
    eqn3.addCoeff(inputs_[1], -1);

    if(vp1 - vp3 > 0)
        eqn2.setSource(Kre_*(vp1 - vp3));
    else
        eqn2.setSource(Kloss_*(vp1 - vp3));

    if(vp2 - vp3 > 0)
        eqn3.setSource(Kre_*(vp2 - vp3));
    else
        eqn3.setSource(Kloss_*(vp2 - vp3));

    nodes_[0]->setEquation(eqn1);
    nodes_[1]->setEquation(eqn2);
    nodes_[2]->setEquation(eqn3);
}
