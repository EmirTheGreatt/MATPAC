#include "matrix.h"

Matrix  *tile(Matrix *M, size_t vertical, size_t horizontal)
{
    Matrix  *to_be_returned = new_mat(M -> rows * vertical, M -> cols * horizontal);
    for (size_t i = 0; i < vertical; i++)
    for (size_t j = 0; j < horizontal; j++){
        copy_onto(to_be_returned, M, M -> rows * i, M -> cols * j);
    }
    return to_be_returned;
}
