#include "matrix.h"
#include <stdio.h>

void    display(Matrix *M)
{
    for (size_t row = 0; row < M -> rows; row++)
    {
        for (size_t col = 0; col < M -> cols; col++)
        {
            printf("%6.2lf", get_coeff(M, row, col));
            if (col < M -> cols - 1)
                printf(" , ");
        }
        printf("\n");
    }
}