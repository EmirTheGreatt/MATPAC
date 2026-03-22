#include "matrix.h"
#include <math.h>

double  g_determinant(Matrix *M)
{
	if (M -> rows != M -> cols)
		return NAN;
	double sign = 1; // will be multiplied by -1 for each row_swap
	int flag;	
	for (size_t col = 0; col < M-> cols; col++)
	{
		if (get_coeff(M, col, col) == 0)
		{
			flag = 0;
			for (size_t row = col + 1; row < M -> rows; row++)
			{
				if (get_coeff(M, row, col) != 0){
					row_swap(M, col, row);
					sign *= -1;
					flag = 1;
					break;
				}
			}
			if (flag == 0)
				return 0;
		}
		for (size_t row = col + 1; row < M -> rows; row++)
			add_row(M, col, row, -get_coeff(M, row ,col) / get_coeff(M, col, col));
	}
	double to_be_returned = 1;
	for (size_t i = 0; i < M->rows; i++)
		to_be_returned *= get_coeff(M, i, i);
	to_be_returned *= sign;
	return to_be_returned;
}