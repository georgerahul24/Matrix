#include <stdlib.h>
#include "stdio.h"

#ifndef MATRIX_IN_C_LIBRARY_H
#define MATRIX_IN_C_LIBRARY_H

typedef struct Matrix {
    int M;
    int N;
    int **matrix;
} Matrix;


int open_file(const char *filename, FILE **f);

void matrix_dimensions(int *M, int *N, FILE *f);

int **read_matrix_values(int M, int N, FILE *f);

void printMatrix(Matrix *matrix, const char *string);

int count_zeros(Matrix *matrix);

void read_Matrix(Matrix *matrix, FILE *f1);

int is_sparse(Matrix *matrix);

Matrix * create_sparse(Matrix *matrix);

#endif //MATRIX_IN_C_LIBRARY_H
