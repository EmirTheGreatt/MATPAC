#include "matrix.h"
#include <stdlib.h>

Matrix  *new_mat(size_t rows, size_t cols)
{
    Matrix *to_be_returned = malloc(sizeof(Matrix));
    to_be_returned -> rows = rows;
    to_be_returned -> cols = cols;
    to_be_returned -> data = malloc(rows * cols * sizeof(double));
    return to_be_returned;
}