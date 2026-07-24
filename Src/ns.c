#include "matrix.h"
#include <string.h>

Matrix  *ns(size_t rows, size_t cols, double l)
{
    Matrix *to_be_returned = new_mat(rows, cols);
    for (size_t row = 0; row < to_be_returned -> rows; row++)
    for (size_t col = 0; col < to_be_returned -> cols; col++)
        *get_ptr(to_be_returned, row, col) = l;
    return to_be_returned;
}