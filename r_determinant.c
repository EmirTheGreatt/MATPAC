#include "matrix.h"
#include <stdlib.h>
#include <math.h>

double  r_determinant(Matrix *M)
{
    if (M -> rows != M -> cols || M -> rows == 0)
        return NAN;
    size_t n = M -> rows;
    if (n == 1)
    {
        return get_coeff(M, 0, 0);
    }
    double  to_be_returned = 0;
    double  flag = 1;
    Matrix  *submat;
    Matrix  *l_submat;
    Matrix  *r_submat;
    for (size_t i = 0; i < M -> cols; i++)
    {
        l_submat = submatrix(M, 1, n, 0, i, 1, 1);
        r_submat = submatrix(M, 1, n, i + 1, n, 1, 1);
        submat = hconcat(l_submat, r_submat);
        to_be_returned += flag * get_coeff(M,0,i) * r_determinant(submat);
        free(l_submat);
        free(r_submat);
        free(submat);
        flag *= -1;
    }
    return to_be_returned;

}