#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#include "matrix_mult.h"

int main() {
    int A[N][N], B[N][N], C[N][N];
    int n, i, j;

    printf("Enter the size of matrices: ");
    scanf("%d", &n);

    printf("Enter matrix A:\n");
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter matrix B:\n");
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    matrix_mult(A, B, C, n);

    printf("Result matrix C:\n");
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
