#include "matrix.h"

Matrix  *kronecker(Matrix *M1, Matrix *M2)
{
	if (M1 -> rows != M2 -> rows || M1 -> cols != M2 -> cols)
	{
		return NULL;
	}
	Matrix *to_be_returned = new_mat(M1 -> rows, M1 -> cols);
	for (size_t row = 0; row < M1 -> rows; row++)
	for (size_t col = 0; col < M1 -> cols; col++)
		set_coeff(to_be_returned, row, col, 
			get_coeff(M1, row, col) * get_coeff(M2, row, col));
	return to_be_returned;
}