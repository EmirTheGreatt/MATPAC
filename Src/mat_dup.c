#include "matrix.h"
#include <stdlib.h>
#include <string.h>

Matrix  *mat_dup(Matrix *M){
    if (!M)
        return NULL;
    Matrix *to_be_returned = malloc(sizeof(Matrix));
    if (!to_be_returned)
        return NULL;
    to_be_returned -> cols = M -> cols;
    to_be_returned -> rows = M -> rows;
    size_t size = sizeof(double) * M -> cols * M -> rows;
    to_be_returned -> data = malloc(size);
    if (!(to_be_returned -> data)){
        free(to_be_returned);
        return NULL;
    }
    memcpy(to_be_returned -> data ,M -> data, size);
    return to_be_returned;
}