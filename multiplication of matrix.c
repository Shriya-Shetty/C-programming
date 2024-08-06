#include <stdio.h>

int main() {
    // Input the matrix1
    int row1, col1;
    printf("Enter row and column of matrix 1:\n");
    scanf("%d %d", &row1, &col1);

    int matrix1[row1][col1];
    int i, j;

    for (i = 0; i < row1; i++) {
        for (j = 0; j < col1; j++) {
            printf("Enter element[%d][%d] of matrix 1: ", i, j);
            scanf("%d", &matrix1[i][j]);
        }
    }

    // Input the matrix2
    int row2, col2;
    printf("Enter row and column of matrix 2:\n");
    scanf("%d %d", &row2, &col2);

    int matrix2[row2][col2];

    for (i = 0; i < row2; i++) {
        for (j = 0; j < col2; j++) {
            printf("Enter element[%d][%d] of matrix 2: ", i, j);
            scanf("%d", &matrix2[i][j]);
        }
    }

    // Printing matrix1
    printf("Matrix 1:\n");
    for (i = 0; i < row1; i++) {
        for (j = 0; j < col1; j++) {
            printf("%d\t", matrix1[i][j]);
        }
        printf("\n");
    }

    // Printing matrix2
    printf("Matrix 2:\n");
    for (i = 0; i < row2; i++) {
        for (j = 0; j < col2; j++) {
            printf("%d\t", matrix2[i][j]);
        }
        printf("\n");
    }

    // Multiplying matrices
    if (col1 != row2) {
        printf("Cannot multiply matrices: Incompatible dimensions.\n");
        return 1;
    }

    int multiMatrix[row1][col2];
    int k;

    for (i = 0; i < row1; i++) {
        for (k = 0; k < col2; k++) {
            multiMatrix[i][k] = 0;
            for (j = 0; j < col1; j++) {
                multiMatrix[i][k] += matrix1[i][j] * matrix2[j][k];
            }
        }
    }

    // Printing the Resultant matrix
    printf("Result of multiplication:\n");
    for (i = 0; i < row1; i++) {
        for (k = 0; k < col2; k++) {
            printf("%d\t", multiMatrix[i][k]);
        }
        printf("\n");
    }

    return 0;
}
