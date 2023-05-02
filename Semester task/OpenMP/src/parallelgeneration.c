#include "parallelgeneration.h"

double multiplyMatrixParallel(int *A, int *B, int *C, int size, int thread_num)
{
    double start_time;
    start_time = omp_get_wtime();

    int i, j, k;
#pragma omp parallel for num_threads(thread_num) private(j, k)
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            for (k = 0; k < size; k++)
            {
                C[i] += (int)A[k] * (int)B[j];
            }
        }
    }

    double end_time;
    end_time = omp_get_wtime();

    double run_time;
    run_time = end_time - start_time;

    return run_time;
}