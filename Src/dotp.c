#include "matrix.h"
#include <math.h>

double  dotp(Matrix *M1, Matrix *M2)
{
    if (M1 -> cols != M2 -> cols || M1 -> rows != M2 -> rows)
        return NAN;
    double to_be_returned = 0;
    for (size_t i = 0; i < M1 -> rows; i++)
        to_be_returned += get_coeff(M1, i, 0) * get_coeff(M2, i, 0);
    return to_be_returned;
}