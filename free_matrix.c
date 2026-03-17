#include "matrix.h"
#include <stdlib.h>

void    free_matrix(Matrix *M)
{
    free(M -> data);
    free(M);
} // Frees M -> data and M, UB if M is not in allocated memory
