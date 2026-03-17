#include "matrix.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
    double arr[9] = {0};
    double arr2[9] = {1,2,3,4,5,6,7,8,9};
    Matrix M1, M2;
    M1.cols = M2.cols = 3;
    M1.rows = M2.rows = 3;
    M1.data = arr;
    M2.data = arr2;
    add_inplace(&M1, &M2);
    add_inplace(&M1, &M2);
    add_inplace(&M1, &M2);
    add_inplace(&M1, &M2);
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++)
        printf("%.1lf,  ", get_coeff(&M1, i, j));printf("\n");}
    
}