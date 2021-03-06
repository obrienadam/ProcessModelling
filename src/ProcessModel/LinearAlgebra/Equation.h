#ifndef EQUATION_H
#define EQUATION_H

#include <vector>
#include <utility>
#include <memory>

class Node;

class Equation
{
public:
    Equation();

    const std::vector<std::pair<std::shared_ptr<Node>, double>>& coeffs() const { return coeffs_; }

    double source() const { return source_; }

    void addCoeff(std::shared_ptr<Node>& node, double coeff);

    void setSource(double source);

    void reset();

    //- Iterators
    std::vector<std::pair<std::shared_ptr<Node>, double>>::iterator begin() { return coeffs_.begin(); }
    std::vector<std::pair<std::shared_ptr<Node>, double>>::iterator end() { return coeffs_.end(); }

    std::vector<std::pair<std::shared_ptr<Node>, double>>::const_iterator begin() const { return coeffs_.begin(); }
    std::vector<std::pair<std::shared_ptr<Node>, double>>::const_iterator end() const { return coeffs_.end(); }

private:

    std::vector<std::pair<std::shared_ptr<Node>, double>> coeffs_;
    double source_;
};

#endif // EQUATION_H
