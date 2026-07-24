#include "matrix.h"

double  get_coeff(Matrix *M, size_t row, size_t col)
{
    return *get_ptr(M, row, col);
}