#include "matrix.h"

Matrix  *rand_mat(size_t rows, size_t cols, double (*rng)(void))
{
	Matrix *to_be_returned = new_mat(rows, cols);
	for (size_t row = 0; row < rows; row++)
	for (size_t col = 0; col < cols; col++)
		set_coeff(to_be_returned, row, col, (*rng)());
	return to_be_returned;
}