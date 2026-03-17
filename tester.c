#include "matrix.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
    double arr1[9] = {1,0,1,0,1,0,1,5,-9};
    double arr2[9] = {-5,2,3,11,0,5,7,8,2};

    Matrix M1, M2, *M;
    M1.cols = M2.cols = 3;
    M1.rows = M2.rows = 3;
    M1.data = arr1;
    M2.data = arr2;
    M = mat_add(&M1, &M2);

    display(&M1);
    printf("\n");
    display(&M2);
    printf("\n");
    display(M);
}