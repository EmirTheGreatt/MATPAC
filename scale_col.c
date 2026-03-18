#include "matrix.h"

void    scale_col(Matrix *M, size_t col, double scalar)
{
    for (size_t row = 0; row < M -> rows; row++)
    {
        *get_ptr(M, row, col) *= scalar;
    }
}