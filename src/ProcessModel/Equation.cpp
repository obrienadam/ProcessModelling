#include "Equation.h"
#include "Node.h"

Equation::Equation()
    :
      source_(0.)
{

}

void Equation::setCoeff(Node *node, double coeff)
{
    coeffs_.push_back(std::make_pair(node, coeff));
}

void Equation::setSource(double source)
{
    source_ = source;
}
