#include "matrix.h"

Matrix  *scalar_mul(Matrix *M, double scalar)
{
    Matrix *to_be_returned = mat_dup(M);
    scale(to_be_returned, scalar);
    return to_be_returned;
}