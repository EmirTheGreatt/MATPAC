#include "matrix.h"
#include <stdlib.h>

Matrix  *rand_int(size_t rows, size_t cols, int min, int max)
{
	Matrix *to_be_returned = new_mat(rows, cols);
	for (size_t row = 0; row < rows; row++)
	for (size_t col = 0; col < cols; col++)
		set_coeff(to_be_returned, row, col, 
			(double)((rand() % (max - min)) + min));
	return to_be_returned;
}