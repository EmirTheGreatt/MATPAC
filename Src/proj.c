#include "matrix.h"

Matrix  *proj(Matrix *vector, Matrix *direction)
{
	double denom = dotp(direction, direction);
	if (denom == 0.0)
		return NULL;
	return scalar_mul(direction ,dotp(vector, direction) / denom);
}