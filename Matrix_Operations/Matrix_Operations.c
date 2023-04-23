#include "Matrix_Operations.h"
#include <stdio.h>
#include <stdlib.h>


void matrix_dimensions(int *M, int *N, FILE *f) {
    /**
     * Reads from the file pointer and returns the dimenstions of the matrix
     */

    fscanf(f, "%d %d", M, N);
}

int **read_matrix_values(int M, int N, FILE *f) {
    /**
     * Reads the values of the matrix
     */
    int **matrix = (int **) malloc(sizeof(int *) * M);
    for (int i = 0; i < M; i++) {
        int *row = malloc(sizeof(int) * N);
        for (int j = 0; j < N; j++) {
            fscanf(f, "%d ", &row[j]);
        }
        matrix[i] = row;
    }
    return matrix;
}


void printMatrix(Matrix *matrix, const char *string) {
    /**
     * Print the matrix
     */
    printf(string);

    for (int i = 0; i < matrix->M; i++) {
        for (int j = 0; j < matrix->N; j++) {
            printf("%d ", matrix->matrix[i][j]);
        }
        printf("\n");
    }
}

int open_file(const char *filename, FILE **f) {
    *f = fopen(filename, "r");

    if (*f == NULL) {
        return -1;
    } else {
        return 0;
    }
}

int count_zeros(Matrix *matrix) {
    int counter = 0;
    for (int i = 0; i < matrix->M; i++) {
        for (int j = 0; j < matrix->N; j++) {
            if (matrix->matrix[i][j] == 0) counter++;
        }

    }
    return counter;
}

void read_Matrix(Matrix *matrix, FILE *f1) {
    int M1, N1;
    matrix_dimensions(&M1, &N1, f1);
    int **Matrix_A;

    Matrix_A = read_matrix_values(M1, N1, f1);

    matrix->matrix = Matrix_A;
    matrix->M = M1;
    matrix->N = N1;

}

int is_sparse(Matrix *matrix) {
    int number_of_zeros = count_zeros(matrix);
    return number_of_zeros >
           ((matrix->M * matrix->N) / 2 != 0) ? 1 : -1;
}

Matrix *create_sparse(Matrix *matrix) {
    Matrix *sparseMatrix = (Matrix *) malloc(sizeof(Matrix));

    int number_of_zeros = count_zeros(matrix);

    int N = 3;
    int M = (matrix->M * matrix->N) - number_of_zeros;
    sparseMatrix->M = M;
    sparseMatrix->N = N;

    int **matrixA = (int **) malloc(sizeof(int *) * M);
    int row_counter = 0;
    for (int i = 0; i < matrix->M; i++) {

        for (int j = 0; j < matrix->N; j++) {
            if (matrix->matrix[i][j] != 0) {
                int *row = (int *) malloc(sizeof(int) * 3);
                row[0] = i;
                row[1] = j;
                row[2] = matrix->matrix[i][j];
                matrixA[row_counter++] = row;
            }

        }
    }

    sparseMatrix->matrix = matrixA;
    return sparseMatrix;


}






