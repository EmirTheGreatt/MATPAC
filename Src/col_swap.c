#include "matrix.h"

void    col_swap(Matrix *M, size_t col1, size_t col2)
{
    for (size_t i = 0; i < M -> rows; i++)
    {
        swap(get_ptr(M, i, col1), get_ptr(M, i, col2));
    }
}