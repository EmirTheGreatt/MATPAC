#include "matrix.h"
#include <string.h>

Matrix  *vconcat(Matrix *M1, Matrix *M2)
{
    if (M1 -> cols != M2 -> cols)
        return NULL;
    Matrix *to_be_returned = new_mat(M1 -> rows + M2 -> rows, M1 -> cols);
    for (size_t row = 0; row < M1 -> rows; row++)
    {
        memcpy(get_ptr(to_be_returned, row, 0), get_ptr(M1, row, 0), sizeof(double)* to_be_returned -> cols);
    }
    for (size_t row = 0; row < M2 -> rows; row++)
    {
        memcpy(get_ptr(to_be_returned, row + M1 -> rows, 0), get_ptr(M2, row, 0), sizeof(double)* to_be_returned -> cols);
    }
    return to_be_returned;
}