#include <stdio.h>

#define SIZE 5

void addMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int ans[SIZE][SIZE]) {
    for (int x = 0; x < SIZE; x++) {
        for (int y = 0; y < SIZE; y++) {
            ans[x][y] = m1[x][y] + m2[x][y];
        }
    }
}

void multiplyMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int ans[SIZE][SIZE]) {
    for (int x = 0; x < SIZE; x++) {
        for (int y = 0; y < SIZE; y++) {
            ans[x][y] = 0;  //Initializing result
            for (int z = 0; z < SIZE; z++) {
                ans[x][y] += m1[x][z] * m2[z][y];
            }
        }
    }
}

void transposeMatrix(int matrix[SIZE][SIZE], int ans[SIZE][SIZE]) {
    for (int x = 0; x < SIZE; x++) {
        for (int y = 0; y < SIZE; y++) {
            ans[y][x] = matrix[x][y];
        }
    }
}

void printMatrix(int matrix[SIZE][SIZE]) {
    for (int x = 0; x < SIZE; x++) {
        for (int y = 0; y < SIZE; y++) {
            printf("%d ", matrix[x][y]);
        }
        printf("\n");
    }
}

int main() {
    int m1[SIZE][SIZE] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };

    int m2[SIZE][SIZE] = {
        {25, 24, 23, 22, 21},
        {20, 19, 18, 17, 16},
        {15, 14, 13, 12, 11},
        {10, 9, 8, 7, 6},
        {5, 4, 3, 2, 1}
    };

    int sum[SIZE][SIZE];
    int product[SIZE][SIZE];
    int transpose[SIZE][SIZE];

    addMatrices(m1, m2, sum);
    printf("Sum of matrices:\n");
    printMatrix(sum);

    multiplyMatrices(m1, m2, product);
    printf("\nProduct of matrices:\n");
    printMatrix(product);

    transposeMatrix(m1, transpose);
    printf("\nTranspose of matrix 1:\n");
    printMatrix(transpose);

    return 0;
}
