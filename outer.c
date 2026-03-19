#include "matrix.h"

Matrix  *outer(Matrix *M1, Matrix *M2)
{
	if (M1 -> cols != 1 || M2 -> cols != 1)
	{
		return NULL;
	}
	Matrix *to_be_returned = new_mat(M1 -> rows, M2 -> rows);
	
}