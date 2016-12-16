#include "Tee.h"
#include "Connector.h"

TJunction::TJunction()
    :
      Block(1, 2, 0, "Tee", "Tee")
{
    addProperty("Loss coefficient", "K", 1., 0.01, 1.);
}

void TJunction::setNodeEquations()
{
    Node* input = inputs_.front().get();
    Node* output1 = outputs_[0].get();
    Node* output2 = outputs_[1].get();

    Equation eqn1, eqn2, eqn3;
    double k = properties_.find("Loss coefficient")->second.value;

    eqn1.addCoeff(input, k);
    eqn1.addCoeff(output1, -1);

    eqn2.addCoeff(input, k);
    eqn2.addCoeff(output2, -1);

    double r1 = input->connector().getResistance();
    double r2 = output1->connector().getResistance();
    double r3 = output2->connector().getResistance();

    eqn3.addCoeff(input->connector().sourceNode(), 1/r1);
    eqn3.addCoeff(input, -1/r1);

    eqn3.addCoeff(output1, -1/r2);
    eqn3.addCoeff(output1->connector().destNode(), 1/r2);

    eqn3.addCoeff(output2, -1/r3);
    eqn3.addCoeff(output2->connector().destNode(), 1/r3);

    input->setEquation(eqn1);
    output1->setEquation(eqn2);
    output2->setEquation(eqn3);
}
