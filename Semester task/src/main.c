#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>

#include "matrix_mult.h"
#include "display_result.h"
#include "handleinput.h"

int main(int argc, char *argv[]) {
    int A[N][N], B[N][N], C[N][N];
    int n, i, j, numOfSpaces;

    printf("Enter the size of matrices: ");
    n = getOneIntInput(1, 5, numOfSpaces);

    printf("Enter matrix A:\n");
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            A[i][j] = getOneIntInput(1, 1000, numOfSpaces);
        }
    }

    printf("Enter matrix B:\n");
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            B[i][j] = getOneIntInput(1, 1000, numOfSpaces);
        }
    }

    matrix_mult(A, B, C, n);

    printOutRes(A, B, C, n, numOfSpaces);

    return 0;
}
