#include "matrix.h"

void    scale_row(Matrix *M, size_t row, double scalar)
{
    for (size_t col = 0; col < M -> cols; col++)
    {
        *get_ptr(M, row, col) *= scalar;
    }
}