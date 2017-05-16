#include "Tee.h"
#include "Connector.h"

TJunction::TJunction()
    :
      Block(0, 0, 3, "Tee", "Tee")
{
    addProperty(Property("K", "Loss coefficient", 1., 0.01, 1., Unit("N/A")));
}

void TJunction::setNodeEquations()
{
    Equation eqns[3];
    double r[3];

    r[0] = nodes_[0]->connector().getResistance();
    r[1] = nodes_[1]->connector().getResistance();
    r[2] = nodes_[2]->connector().getResistance();

    //- Continuity equation
    eqns[0].addCoeff(nodes_[0]->connector().otherNode(nodes_[0].get()), r[1]*r[2]);
    eqns[0].addCoeff(nodes_[0].get(), -r[1]*r[2]);

    eqns[0].addCoeff(nodes_[1]->connector().otherNode(nodes_[1].get()), r[0]*r[2]);
    eqns[0].addCoeff(nodes_[1].get(), -r[0]*r[2]);

    eqns[0].addCoeff(nodes_[2]->connector().otherNode(nodes_[2].get()), r[0]*r[1]);
    eqns[0].addCoeff(nodes_[2].get(), -r[0]*r[1]);

    std::vector<Node*> inlets, outlets;

    for(auto& node: nodes_)
    {
        double p1 = node->getSolution("P");
        double p2 = node->connector().otherNode(node.get())->getSolution("P");

        if(p1 > p2) // outlet
            outlets.push_back(node.get());
        else
            inlets.push_back(node.get());
    }

    double k = properties_["K"].value;

    if(inlets.size() == 1)
    {
        eqns[1].addCoeff(inlets.back(), k);
        eqns[1].addCoeff(outlets[0], -1);

        eqns[2].addCoeff(inlets.back(), k);
        eqns[2].addCoeff(outlets[1], -1);
    }
    else
    {
    //- Pressure equivalency (ideal connector)
        eqns[1].addCoeff(nodes_[0].get(), 1.);
        eqns[1].addCoeff(nodes_[1].get(), -1.);

        eqns[2].addCoeff(nodes_[0].get(), 1.);
        eqns[2].addCoeff(nodes_[2].get(), -1.);
    }

    for(int i = 0; i < 3; ++i)
        nodes_[i]->setEquation(eqns[i]);
}
