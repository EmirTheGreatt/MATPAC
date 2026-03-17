#include <stddef.h>
typedef struct{
    size_t  rows;
    size_t  cols;
    double  *data;
} Matrix;

void    add_inplace(Matrix *M1, Matrix *M2);
Matrix  *mat_dup(Matrix *M);
Matrix  *mat_add(Matrix *M1, Matrix *M2);
double  *get_ptr(Matrix *M, size_t row, size_t col);
double  get_coeff(Matrix *M, size_t row, size_t col);