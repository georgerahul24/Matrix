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

    Matrix *sMatrixA, *sMatrixB;
    sMatrixA = create_sparse(&MatrixA);
    printMatrix(sMatrixA,
                "Sparse Matrix A:\n");

    sMatrixB = create_sparse(&MatrixB);
    printMatrix(sMatrixB,
                "Sparse Matrix B:\n");
}

