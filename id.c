#include "matrix.h"

Matrix  *id(size_t n)
{
    Matrix *to_be_returned = zeros(n, n);
    for (size_t i = 0; i < n; i++)
        *get_ptr(to_be_returned, i, i) = 1;
    return to_be_returned;
}