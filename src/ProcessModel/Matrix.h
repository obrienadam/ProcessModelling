#ifndef MATRIX_H
#define MATRIX_H

#include <armadillo>

class Matrix
{
public:
    Matrix();
    void init(int rows, int cols, int nNonZeros = 0);

    void add(int row, int col, double val);
    double get(int row, int col) const;

private:
    std::vector<int> rowInds_;
    std::vector<int> cols_;
    std::vector<double> vals_;
};

#endif // MATRIX_H
