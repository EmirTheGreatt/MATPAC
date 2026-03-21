#include "matrix.h"

void    add_const(Matrix *M, double d)
{
	for (size_t row = 0; row < M -> rows; row++)
	for (size_t col = 0; col < M -> cols; col++)
		set_coeff(M, row, col, d);

}