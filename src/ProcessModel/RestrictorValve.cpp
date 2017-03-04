#include "RestrictorValve.h"
#include "Connector.h"

RestrictorValve::RestrictorValve()
    :
      Block(0, 0, 2, "Restrictor Valve", "R-Valve")
{
    addProperty(Property("Target flow rate", "Qobj", 1., 0., 1000., Unit("m^3/s", 1.)));
    addProperty(Property("Minimum resistance", "rmin", 0, 0., 100., Unit("m^3/s", 1.)));
    solution_["Resistance"] = Property("Resistance", "r");
    solution_["Pressure drop"] = Property("Pressure drop", "dp");
    solution_["Flow rate"] = Property("Flow rate", "Q", 0., -1e-12, 1e12, Unit("m^3/s"));
}

void RestrictorValve::setNodeEquations()
{
    double p1 = nodes_[0]->connector().otherNode(nodes_[0].get())->getSolutionVariable("Pressure");
    double p2 = nodes_[0]->getSolutionVariable("Pressure");
    double p3 = nodes_[1]->getSolutionVariable("Pressure");
    double p4 = nodes_[1]->connector().otherNode(nodes_[1].get())->getSolutionVariable("Pressure");

    double Qobj = properties_["Target flow rate"].value;

    double r1 = nodes_[0]->connector().getResistance();
    double r2 = nodes_[1]->connector().getResistance();

    //- Probe to see what the pressure drop across the entire line is

    double r = std::max(fabs(p1 - p4)/Qobj - r1 - r2, properties_["Minimum resistance"].value);
    setSolution("Resistance", r);
    setSolution("Pressure drop", fabs(p2 - p3));

    Equation eqn1, eqn2;

    if(r != 0.)
    {
        //- Continuity 1
        eqn1.addCoeff(nodes_[0].get(), r);
        eqn1.addCoeff(nodes_[0]->connector().otherNode(nodes_[0].get()), -r);

        eqn1.addCoeff(nodes_[0].get(), r1);
        eqn1.addCoeff(nodes_[1].get(), -r1);

        //- Continuity 2
        eqn2.addCoeff(nodes_[1].get(), r);
        eqn2.addCoeff(nodes_[1]->connector().otherNode(nodes_[1].get()), -r);

        eqn2.addCoeff(nodes_[1].get(), r2);
        eqn2.addCoeff(nodes_[0].get(), -r2);
    }
    else
    {
        //- Continuity
        eqn1.addCoeff(nodes_[0].get(), 1/r1);
        eqn1.addCoeff(nodes_[0]->connector().otherNode(nodes_[0].get()), -1/r1);

        eqn1.addCoeff(nodes_[1].get(), 1/r2);
        eqn1.addCoeff(nodes_[1]->connector().otherNode(nodes_[1].get()), -1/r2);

        //- Equal inlet/outlet pressures
        eqn2.addCoeff(nodes_[0].get(), 1);
        eqn2.addCoeff(nodes_[1].get(), -1);
    }

    nodes_[0]->setEquation(eqn1);
    nodes_[1]->setEquation(eqn2);
}

void RestrictorValve::updateSolution()
{
    setSolution("Flow rate", nodes_[1]->connector().getSolutionVariable("Flow rate"));
}
