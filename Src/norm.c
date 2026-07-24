#include "matrix.h"
#include <math.h>

double  norm(Matrix *M)
{
    double to_be_returned_squared = 0;
    for (size_t row = 0; row < M -> rows; row++)
    for (size_t col = 0; col < M -> cols; col++)
        to_be_returned_squared += get_coeff(M, row, col) * get_coeff(M, row, col);
    return sqrt(to_be_returned_squared);
}