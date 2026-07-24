#include "matrix.h"
#include <math.h>
#define  ABS(X)     (X > 0 ? X : -X)

double  pnorm(Matrix *M, double p)
{
    double to_be_returned_tothep = 0;
    for (size_t row = 0; row < M -> rows; row++)
    for (size_t col = 0; col < M -> cols; col++)
        to_be_returned_tothep += pow(ABS(get_coeff(M, row, col)), p);
    return pow(to_be_returned_tothep, 1.0 / p);
}