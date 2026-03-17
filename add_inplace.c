#include "matrix.h"
#include <stdlib.h>

void add_inplace(Matrix *M1, Matrix *M2)
{
	if (M1 -> cols != M2 -> cols || M1 -> rows != M2 -> rows)
        return ;
    double *ptr;
    for (size_t row = 0; row < M1 -> rows; row++)
        for (size_t col = 0; col < M2 -> cols; col++)
        {
            ptr = get_ptr(M1, row, col);
            *ptr = get_coeff(M2, row, col) + (*ptr);
        }
    return ;
}