#include "matrix.h"

void  gram_schmidt(Matrix *M)
{
	Matrix	*projection = zeros(M -> rows, 1);
	Matrix	*baby_proj;
	Matrix	*current;
	Matrix	*projectee;
	for (size_t col1 = 0; col1 < M -> cols; col1++)
	{
		current = submatrix(M, 0, M -> rows, col1, col1 + 1, 1, 1);
		for (size_t col2 = 0; col2 < col1; col2++)
		{
			projectee = submatrix(M, 0, M -> rows, col2, col2 + 1, 1, 1);
			baby_proj = proj(current, projectee);
			add_inplace(projection, baby_proj);
			free_matrix(projectee);
			free_matrix(baby_proj);
		}
		scale(projection, -1.0);
		add_inplace(current, projection);
		copy_onto(M, current, 0, col1);
		free_matrix(current);
		set_mat(projection, 0);
	}
}
