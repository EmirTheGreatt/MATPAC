#include <stddef.h>
typedef struct{
    size_t  rows;
    size_t  cols;
    double  *data;
} Matrix;

void    add_inplace(Matrix *M1, Matrix *M2);
void    display(Matrix *M);
Matrix  *mat_dup(Matrix *M);
Matrix  *mat_add(Matrix *M1, Matrix *M2);
double  *get_ptr(Matrix *M, size_t row, size_t col);
double  get_coeff(Matrix *M, size_t row, size_t col);
void    scale(Matrix *M, double scalar);
Matrix  *scalar_mul(Matrix *M, double scalar);
void    free_matrix(Matrix *M); // Frees M -> data and M, UB if M is not in allocated memory
Matrix  *new_mat(size_t rows, size_t cols); // Declares a new matrix and allocates rows*cols*sizeof(double) memory without initializing
Matrix  *hconcat(Matrix *M1, Matrix *M2);
Matrix  *vconcat(Matrix *M1, Matrix *M2);
Matrix  *ns(size_t rows, size_t cols, double l);
Matrix  *zeros(size_t rows, size_t cols);
Matrix  *id(size_t n);
Matrix  *transpose(Matrix *M);
Matrix  *mat_mul(Matrix *M1, Matrix *M2);