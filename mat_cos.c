#include "matrix.h"
#include <math.h>

double  mat_cos(Matrix *M1, Matrix *M2)
{
	double norm1 = norm(M1), norm2 = norm(M2);
	if (norm1 == 0 || norm2 == 0)
		return NAN;
	return dotp(M1, M2) / norm1 / norm2;
}