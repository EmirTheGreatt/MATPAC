#include "matrix.h"

double *get_ptr(Matrix *M, size_t row, size_t col)
{
    return &(M -> data)[(M -> cols) * row + col];
}