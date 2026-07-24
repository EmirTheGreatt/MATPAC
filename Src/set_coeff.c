#include "matrix.h"

void    set_coeff(Matrix *M, size_t row, size_t col, double scalar)
{
    *get_ptr(M, row, col) = scalar;
}