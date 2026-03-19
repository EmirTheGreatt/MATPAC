#include "matrix.h"

void    set_mat(Matrix *M, double scalar)
{
	for (size_t row = 0; row < M -> rows; row++)
	{
		for (size_t col = 0; col < M -> cols; col++)
			set_coeff(M, row, col, scalar);
	}
}