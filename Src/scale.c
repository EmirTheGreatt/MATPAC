#include "matrix.h"

void    scale(Matrix *M, double scalar)
{
    for (size_t i = 0; i < M -> rows; i++){
        for (size_t j = 0; j < M -> cols; j++){
            *get_ptr(M, i, j) *= scalar;
        }
    }
}