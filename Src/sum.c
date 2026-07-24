#include "matrix.h"

double  sum(Matrix *M)
{
	double to_be_returned = 0;
	for (size_t row = 0; row < M->rows; row++)
	for (size_t col = 0; col < M->cols; col++)
		to_be_returned += get_coeff(M, row, col);
	return to_be_returned;

}