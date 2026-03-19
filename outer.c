#include "matrix.h"

Matrix  *outer(Matrix *M1, Matrix *M2)
{
	if (M1 -> cols != 1 || M2 -> cols != 1)
	{
		return NULL;
	}
	Matrix *to_be_returned = new_mat(M1 -> rows, M2 -> rows);
	for (size_t row = 0; row < M1 -> rows; row++)
	for (size_t col = 0; col < M2 -> rows; col++)
		set_coeff(to_be_returned, row, col,
			get_coeff(M1, row, 0) * get_coeff(M2, col, 0));
	return to_be_returned;

}