#include "parallelgeneration.h"

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