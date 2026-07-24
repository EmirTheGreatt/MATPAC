#include "matrix.h"

Matrix  *map(Matrix *M, double (*f)(double))
{
    Matrix *to_be_returned = new_mat(M -> rows, M -> cols);
    for (size_t row = 0; row < M -> rows; row++)
    for (size_t col = 0; col < M -> cols; col++)
        set_coeff(to_be_returned, row, col, (*f)(get_coeff(M, row, col)));
    return to_be_returned;
}