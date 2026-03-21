#include "matrix.h"
#include <stdlib.h>
#include <stdio.h>

double random_double()
{
    return (double)rand() / (double)RAND_MAX;
}

int main()
{
    double arr1[9] = {1,0,1,0,1,0,1,5,-9};
    double arr2[9] = {-5,2,3,11,0,5,7,8,2};
    double arr3[12] = {1,2,8,9,0,1,1,1,1,1,1};
    Matrix M1, M2, *M, M3;
    M1.cols = M2.cols = 3;
    M1.rows = M2.rows = 3;
    M1.data = arr1;
    M2.data = arr2;
    M = mat_add(&M1, &M2);

    M3.rows = 3;
    M3.cols = 4;
    M3.data = arr3;
    Matrix *newM1 = submatrix(&M1, 0, 3, 0, 3, 2, 2);
    Matrix *newM2 = submatrix(&M2, 0, 3, 0, 3, 2, 2);
    

    display(&M1);
    printf("\n");
    display(&M2);
    printf("\n");
    display(newM1);
    printf("\n");
    display(newM2);
    printf("\n");
    Matrix *copyM1 = mat_dup(&M1);
    Matrix *invM1 = id(3);
    display(copyM1);
    printf("\n");
    display(invM1);
    printf("\n");
    add_row(invM1, 0, 2, -1);
    add_row(invM1, 1, 2, -5);
    add_row(invM1, 2, 0, 1.0/10.0);
    scale_row(invM1, 2, -1.0/10.0);

    add_row(copyM1, 0, 2, -1);
    add_row(copyM1, 1, 2, -5);
    add_row(copyM1, 2, 0, 1.0/10.0);
    scale_row(copyM1, 2, -1.0/10.0);
    display(copyM1);
    printf("\n");
    display(invM1);
    printf("\n");
    display(mat_mul(&M1, invM1));
    printf("\n");
    printf("%lf\n", i_determinant(&M1));
    printf("%lf\n", r_determinant(&M1));
    Matrix *randintmat;
    for (int _ = 0; _ < 10; _++){
        randintmat = rand_mat(5, 5, &random_double);
        printf("%dth Matrix : \n", _);
        display(randintmat);
        printf("\n");
        free(randintmat);
    }
    
}