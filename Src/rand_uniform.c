#include "matrix.h"
#include <stdlib.h>

static double rand_double()
{
	return ((double)rand() / (double)RAND_MAX);
}

Matrix  *rand_uniform(size_t rows, size_t cols)
{
	return rand_mat(rows, cols, &rand_double);
}