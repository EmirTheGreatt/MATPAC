#include "matrix.h"
Matrix *mat_add(Matrix *M1, Matrix *M2)
{
    if (M1 -> rows != M2 -> rows || M1 -> cols != M2 -> cols)
        return NULL;
    Matrix *to_be_returned = mat_dup(M1);
    add_inplace(to_be_returned, M2);
    return to_be_returned;
}