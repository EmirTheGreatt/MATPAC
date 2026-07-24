#include "matrix.h"
#include <stdlib.h>
#include <string.h>

Matrix  *hconcat(Matrix *M1, Matrix *M2)
{
    if (M1 -> rows != M2 -> rows)
        return NULL;
    Matrix *to_be_returned = new_mat(M1 -> rows, M1 -> cols + M2 -> cols);
    double *current;
    for (size_t row = 0; row < M1 -> rows; row++)
    {
        current = get_ptr(to_be_returned, row, 0);
        memcpy(current, get_ptr(M1, row, 0), (M1 -> cols) * sizeof(double));
        current = get_ptr(to_be_returned, row, M1 -> cols);
        memcpy(current, get_ptr(M2, row, 0), (M2 -> cols) * sizeof(double));
    }
    return to_be_returned;
}