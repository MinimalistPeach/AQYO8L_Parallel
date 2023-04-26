#include "parallelgeneration.h"

void generateMatrix(int **A, int **B, int **C, int size)
{
    for (int i = 0; i < size; i++)
    {
        A[i] = (int *)malloc(size * sizeof(int));
        B[i] = (int *)malloc(size * sizeof(int));
        C[i] = (int *)malloc(size * sizeof(int));
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            A[i][j] = i + j;
            B[i][j] = i - j;
            C[i][j] = 0.0;
        }
    }
}

double multiplyMatrix(int **A, int **B, int **C, int size)
{
    double start_time;
    start_time = omp_get_wtime();

#pragma omp parallel for
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            for (int k = 0; k < size; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    double end_time;
    end_time = omp_get_wtime();

    double run_time;
    run_time = end_time - start_time;

    return run_time;
}

void freeMemory(int **A, int **B, int **C, int size)
{
     for (int i = 0; i < size; i++) {
        free(A[i]);
        free(B[i]);
        free(C[i]);
    }
    free(A);
    free(B);
    free(C);
}