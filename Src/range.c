#include "matrix.h"

Matrix  *range(double x, double y, size_t n)
{
    Matrix *to_be_returned = new_mat(n, 1);
    for (size_t i = 0; i < n; i++)
    {
        set_coeff(to_be_returned, i, 1, x + (y - x) / (double)n * (double)i);
    }
    return to_be_returned;
}