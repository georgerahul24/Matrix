#include "stdio.h"
#include "Matrix_Operations.h"


int main() {
    FILE *f1;
    open_file("/Users/gr/Desktop/C/Matrix/Matrix.input", &f1);
    Matrix MatrixA, MatrixB;
    read_Matrix(&MatrixA, f1);
    read_Matrix(&MatrixB, f1);

    printMatrix(&MatrixA, "Matrix A:\n");
    printMatrix(&MatrixB, "Matrix B: \n");

    printf("The  Matrix A and Matrix B are %d and %d\n", is_sparse(&MatrixA), is_sparse(&MatrixB));

    sMatrix *sMatrixA, *sMatrixB,*sMatrixC;
    sMatrixA = create_sparse(&MatrixA);
    printSparseMatrix(sMatrixA,
                      "Sparse Matrix A:\n");

    sMatrixB = create_sparse(&MatrixB);
    printSparseMatrix(sMatrixB,
                      "Sparse Matrix B:\n");

    sMatrixC= transpose_sparse(sMatrixA);
    printSparseMatrix(sMatrixC,
                      "Sparse Matrix C:\n");



}

