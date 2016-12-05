#include "Matrix.h"

Matrix::Matrix()
{

}

void Matrix::init(int rows, int cols, int nNonZeros)
{
    rowInds_.resize(rows + 1, 0);
}

void Matrix::add(int row, int col, double val)
{
    int i = rowInds_[row];
    int end = rowInds_[row + 1];

    for(; i < end; ++i)
    {
        if(cols_[i] == col)
        {
            vals_[i] += val;
            return;
        }
        else if(cols_[i] > col)
            break;
    }

    cols_.insert(cols_.begin() + i, col);
    vals_.insert(vals_.begin() + i, val);

    std::transform(rowInds_.begin() + row + 1,
                   rowInds_.end(),
                   rowInds_.begin() + row + 1,
                   [](int ind){ return ind + 1; }
                   );
}

double Matrix::get(int row, int col) const
{
    for(int i = rowInds_[row], end = rowInds_[i + 1]; i < end; ++i)
        if(cols_[i] == col)
            return vals_[i];

    return 0.;
}
