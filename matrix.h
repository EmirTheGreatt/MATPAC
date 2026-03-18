#include <stddef.h>
#define ON_ROWS 0;
#define ON_COLUMNS 1;

typedef struct{
    size_t  rows;
    size_t  cols;
    double  *data;
}   Matrix;

typedef struct{
    Matrix  *P;
    Matrix  *L;
    Matrix  *U;
}   PLU;

typedef struct{
    char    type;
    char    orientation;
    size_t  src;
    size_t  dst;
    double  scalar;
}   ELM; //Questionable choice, could require some rethinking

void    add_inplace(Matrix *M1, Matrix *M2);
void    display(Matrix *M);
Matrix  *mat_dup(Matrix *M);
Matrix  *mat_add(Matrix *M1, Matrix *M2);
double  *get_ptr(Matrix *M, size_t row, size_t col);
double  get_coeff(Matrix *M, size_t row, size_t col);
void    set_coeff(Matrix *M, size_t row, size_t col, double scalar);
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


// Elementary row/column operations
void    swap(double *p1, double *p2);
void    row_swap(Matrix *M, size_t row1, size_t row2);
void    col_swap(Matrix *M, size_t col1, size_t col2);
void    scale_row(Matrix *M, size_t row, double scalar);
void    scale_col(Matrix *M, size_t col, double scalar);
void    add_row(Matrix *M, size_t src_row, size_t dst_row, double scalar);
void    add_col(Matrix *M, size_t src_col, size_t dst_col, double scalar);

// Submatrix & determinan
Matrix  *submatrix(Matrix *M, size_t startrow, size_t endrow, size_t startcol, size_t endcol, size_t steprow, size_t stepcol);
double  r_determinant(Matrix *M);

// Vectors
double  dotp(Matrix *M1, Matrix *M2); // dot product of two column vectors
double  norm(Matrix *M); // 2 norm of an arbitrary matrix
double  pnorm(Matrix *M, double p); // p norm of an arbitrary matrix

// Big guns
// TODO!
// IDEA! Gauss elimination but apply to a new mat too
// example: GaussID(M1, M2); do operations on M1 to get it to be ID but apply same things to M2
// GaussID(M, Vec) solves Mx = Vec
// GaussID(M, id(n)) inverts M
// GaussUP(M, id(n)) LU decomps ?
PLU     PLUdecomp(Matrix *M);
Matrix  *inverse(Matrix *M); // inverts matrix M, returns NULL if M is singular
double  *eigenvalues(Matrix *M);

// Misc
Matrix  *range(double x, double y, size_t n);
Matrix  *reshape(Matrix *M, size_t new_rows, size_t new_cols);
Matrix  *map(Matrix *M, double (*f)(double));
void    copy_onto(Matrix *dst_mat, Matrix *src_mat, size_t row_index, size_t col_index);
Matrix  *tile(Matrix *M, size_t vertical, size_t horizontal);
Matrix  *kronecker(Matrix *M1, Matrix *M2);