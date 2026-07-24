#include <stdlib.h>
#include "matrix.h"

static size_t find_num(size_t start, size_t end, size_t stepsize)
{
    if (end == start)
        return 0;
    end = end - start;
    return (end - 1) / stepsize + 1;
}

// Can't reverse a matrix as of now
Matrix  *submatrix(Matrix *M, size_t startrow, size_t endrow, size_t startcol, size_t endcol, size_t steprow, size_t stepcol)
{
    size_t rows = find_num(startrow, endrow, steprow);
    size_t cols = find_num(startcol, endcol, stepcol);
    Matrix *to_be_returned = new_mat(rows, cols);
    size_t row;
    size_t col;
    for (row = startrow; row < endrow; row += steprow)
    for (col = startcol; col < endcol; col += stepcol)
        *get_ptr(to_be_returned, (row - startrow) / steprow, (col - startcol) / stepcol) = get_coeff(M, row, col);
    return to_be_returned;
}