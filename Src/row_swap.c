#include "matrix.h"

void    row_swap(Matrix *M, size_t row1, size_t row2)
{
    for (size_t i = 0; i < M -> cols; i++)
    {
        swap(get_ptr(M, row1, i), get_ptr(M, row2, i));
    }
}