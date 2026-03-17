#include "matrix.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
    double arr[9] = {0};
    Matrix M;
    M.cols = 3;
    M.rows = 3;
    M.data = arr;
    *get_ptr(&M, 1, 1) = 2;
    *get_ptr(&M, 0, 1) = 6;
    *get_ptr(&M, 0, 2) = 9;


    for (int i = 0; i < 3; i++){
    for (int j = 0; j < 3; j++)
        printf("%lf,", arr[i*3 + j]);printf("\n");}
}