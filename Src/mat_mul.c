#include "matrix.h"

Matrix  *mat_mul(Matrix *M1, Matrix *M2)
{
    if (M1 -> cols != M2 -> rows)
        return NULL;
    Matrix *to_be_returned = new_mat(M1 -> rows, M2 -> cols);
    double *ptr;
    for (size_t row = 0; row < to_be_returned -> rows; row++)
    for (size_t col = 0; col < to_be_returned -> cols; col++)
    {
        ptr = get_ptr(to_be_returned, row, col);
        *ptr = 0;
        for (size_t i = 0; i < M1 -> cols; i++)
        {
            *ptr += get_coeff(M1, row, i) * get_coeff(M2, i, col);
        }
    }
    return to_be_returned;
}