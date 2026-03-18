#include "matrix.h"

void    add_col(Matrix *M, size_t src_col, size_t dst_col, double scalar)
{
    for (size_t row = 0; row < M -> rows; row++)
    {
        *get_ptr(M, row, dst_col) += get_coeff(M, row, src_col) * scalar;
    }
}