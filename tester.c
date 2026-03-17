#include "matrix.h"
#include <stdlib.h>
#include <stdio.h>

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

    display(&M1);
    printf("\n");
    display(&M2);
    printf("\n");
    Matrix *newM1 = submatrix(&M1, 0, 3, 0, 3, 2, 2);
    Matrix *newM2 = submatrix(&M2, 0, 3, 0, 3, 2, 2);
    display(newM1);
    printf("\n");
    display(newM2);
    printf("\n");



}