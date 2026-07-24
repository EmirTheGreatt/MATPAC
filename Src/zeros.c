#include "matrix.h"

Matrix  *zeros(size_t rows, size_t cols)
{
    return ns(rows, cols, 0);
}