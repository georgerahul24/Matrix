#include <stdlib.h>
#include "stdio.h"

#ifndef MATRIX_IN_C_LIBRARY_H
#define MATRIX_IN_C_LIBRARY_H

typedef struct Matrix {
    int M;
    int N;
    int **matrix;
} Matrix;

typedef struct Sparse_Matrix {
    int org_M;
    int ord_N;
    int M;
    int N;
    int **matrix;
} sMatrix;

int open_file(const char *filename, FILE **f);

void matrix_dimensions(int *M, int *N, FILE *f);

int **read_matrix_values(int M, int N, FILE *f);

void printMatrix(Matrix *matrix, const char *string);

int count_zeros(Matrix *matrix);

void read_Matrix(Matrix *matrix, FILE *f1);

int is_sparse(Matrix *matrix);

sMatrix *create_sparse(Matrix *matrix);

void printSparseMatrix(sMatrix *matrix, const char *string);

sMatrix *transpose_sparse(sMatrix *matrix);

int **create_Matrix(int M, int N);

int *create_row(int cols) {
    return (int *) malloc(sizeof(int) * 3);
}

sMatrix addSparseMatrix(sMatrix *sMatrix1, sMatrix *sMatrix2) {

    int **matrix = create_Matrix(sMatrix1->M + sMatrix2->M, 3);
    int i = 0, j = 0, k = 0;

    while (i < sMatrix1->M && j < sMatrix2->M) {
        if (sMatrix1->matrix[i][0]==sMatrix2->matrix[j][0]){

        }
    }


}

#endif //MATRIX_IN_C_LIBRARY_H
