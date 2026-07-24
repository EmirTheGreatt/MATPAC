#include "matrix.h"

void    copy_onto(Matrix *dst_mat, Matrix *src_mat, size_t row_index, size_t col_index)
{
    if (dst_mat -> cols - col_index < src_mat -> cols ||
        dst_mat -> rows - row_index < src_mat -> rows)
        return ;
    for (size_t row = 0; row < src_mat -> rows; row++)
    for (size_t col = 0; col < src_mat -> cols; col++)
        set_coeff(dst_mat, row + row_index, col + col_index,
            get_coeff(src_mat, row, col));
}