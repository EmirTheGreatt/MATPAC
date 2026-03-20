#include "matrix.h"

int	is_equal_eps(Matrix *M1, Matrix *M2, double epsilon)
{
	if (M1 -> rows != M2 -> rows || M1 -> cols != M2 -> cols)
		return 0;
	for (size_t col = 0; col < M1 -> cols; col++)
	for (size_t row = 0; row < M1 -> rows; row++)
		if (ABS(get_coeff(M1, row, col) - get_coeff(M2, row, col)) < epsilon)
			return 0;
	return 1;
}