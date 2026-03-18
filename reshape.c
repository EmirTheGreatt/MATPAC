#include "matrix.h"

Matrix  *reshape(Matrix *M, size_t new_rows, size_t new_cols)
{
    if (M -> rows * M -> cols != new_cols * new_rows)
        return NULL;
    Matrix *to_be_returned= mat_dup(M);
    to_be_returned -> cols = new_cols;
    to_be_returned -> rows = new_rows;
    return to_be_returned;
}