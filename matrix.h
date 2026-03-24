#include <stddef.h>
#define ON_ROWS 0;
#define ON_COLUMNS 1;
#define ABS(X)    (X > 0 ? X : -X)

#define REF     1
#define RREF    2
#define ORT     3
#define nORT    4

typedef struct{
    size_t  rows;
    size_t  cols;
    double  *data;
}   Matrix;

typedef enum
{
    ROW,
    COL
}   orientation;

typedef enum
{
    SWAP,
    ADD,
    SCALE
}   move_type;

typedef struct{
    orientation ordir;
    move_type   type;
    size_t      src;
    size_t      dst; // irrelevant if type is scale
    double      scale; // irrelevant if type is swap
}   elop;


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
double  i_determinant(Matrix *M);
double  g_determinant(Matrix *M); // Computes the determinant by upper triangulising M and multiplying coefficients in the diagonal

// Vectors
double  dotp(Matrix *M1, Matrix *M2); // dot product of matrices viewed as vectors
double  norm(Matrix *M); // 2 norm of an arbitrary matrix
double  pnorm(Matrix *M, double p); // p norm of an arbitrary matrix
Matrix  *proj(Matrix *vector, Matrix *direction); // Projects vector onto direction (orthogonal)
double  mat_cos(Matrix *M1, Matrix *M2); // Takes cosine between M1 and M2 considering them as vectors
void  gram_schmidt(Matrix *M); // Applies gram schmidt to columns of M

// Big guns
// TODO!
// IDEA! Gauss elimination but apply to a new mat too
// example: GaussID(M1, M2); do operations on M1 to get it to be ID but apply same things to M2
// GaussID(M, Vec) solves Mx = Vec
// GaussID(M, id(n)) inverts M
// GaussUP(M, id(n)) LU decomps ?

// Misc
Matrix  *range(double x, double y, size_t n);
Matrix  *reshape(Matrix *M, size_t new_rows, size_t new_cols);
Matrix  *map(Matrix *M, double (*f)(double));
void    copy_onto(Matrix *dst_mat, Matrix *src_mat, size_t row_index, size_t col_index);
Matrix  *tile(Matrix *M, size_t vertical, size_t horizontal);
Matrix  *kronecker(Matrix *M1, Matrix *M2);
Matrix  *outer(Matrix *M1, Matrix *M2);
void    set_mat(Matrix *M1, double scalar);
int     is_equal(Matrix *M1, Matrix *M2);
int     is_equal_eps(Matrix *M1, Matrix *M2, double epsilon); // Difference between each coefficient is less than epsilon
Matrix  *rand_mat(size_t rows, size_t cols, double (*rng)(void));
Matrix  *rand_uniform(size_t rows, size_t cols);
Matrix  *rand_int(size_t rows, size_t cols, int min, int max); // generates a matrix of integers (casted to doubles) between min and max, max excluded min included
void    add_const(Matrix *M, double d);
double  sum(Matrix *M);

// One big row-Gauss.
//TODO!
void apply(elop op, ...);
void Gauss(int target, char *format, Matrix *main, ...); /* 
    elementary row or column operations are applied to main to get it into a form specified by "target"
    REF Row echelon form
    RREF Reduced row echelon form
    format is a string containing letters m and d, 
    each m represents a matrix and each d represents a double, the format then specifies order in which objects in ... appear
    each operation to main is copied to each other object in ...
    if said object is a double, swaps multiply by -1 and scales of a row by \lambda scaled d by same factor*/