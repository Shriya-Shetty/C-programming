#include <stdio.h>

// Function to create a matrix
void makeMatrix(int row, int col, int matrix[row][col]) {
    int i, j;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            printf("Enter element[%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to print a matrix
void printMatrix(int row, int col, int matrix[row][col]) {
    int i, j;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
void addMatrix(int row, int col, int matrix1[row][col], int matrix2[row][col]) {
    int i, j;
    int matrixAdd[row][col];
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            matrixAdd[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    // Printing the added matrix
    printf("Matrix 1 + Matrix 2:\n");
    printMatrix(row, col, matrixAdd);
}

int main() {
    // Input matrix 1
    int row1, col1;
    printf("Enter row and column of matrix 1:\n");
    scanf("%d %d", &row1, &col1);
    int matrix1[row1][col1];
    makeMatrix(row1, col1, matrix1);

    // Input matrix 2
    int row2, col2;
    printf("Enter row and column of matrix 2:\n");
    scanf("%d %d", &row2, &col2);
    int matrix2[row2][col2];
    makeMatrix(row2, col2, matrix2);

    // Printing matrix 1
    printf("Matrix 1:\n");
    printMatrix(row1, col1, matrix1);

    // Printing matrix 2
    printf("Matrix 2:\n");
    printMatrix(row2, col2, matrix2);

    // Adding matrix 1 and matrix 2
    if (row1 == row2 && col1 == col2) {
        addMatrix(row1, col1, matrix1, matrix2);
    } else {
        printf("Cannot add matrices: Dimensions are not the same.\n");
    }

    return 0;
}
