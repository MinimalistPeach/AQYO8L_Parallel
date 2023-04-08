#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#include "matrix_mult.h"

void matrix_mult(int A[][N], int B[][N], int C[][N], int n) {
    int i, j, k;

    #pragma omp parallel for private(j, k)
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            C[i][j] = 0;
            for(k=0; k<n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

