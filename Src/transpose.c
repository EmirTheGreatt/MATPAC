#include "matrix.h"

Matrix  *transpose(Matrix *M)
{
    Matrix *to_be_returned = new_mat(M -> cols, M -> rows);
    for (size_t row = 0; row < to_be_returned -> rows; row++)
    for (size_t col = 0; col < to_be_returned -> cols; col++)
        *get_ptr(to_be_returned, row, col) = get_coeff(M, col, row);
    return to_be_returned;
}