#include "matrix.h"

void    add_row(Matrix *M, size_t src_row, size_t dst_row, double scalar)
{
    for (size_t col = 0; col < M -> cols; col++)
    {
        *get_ptr(M, dst_row, col) += get_coeff(M, src_row, col) * scalar;
    }
}