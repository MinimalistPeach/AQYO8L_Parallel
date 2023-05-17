#include "sequentialgeneration.h"

double multiplyMatrixSeq(int *A, int *B, int *C, int size)
{
    double start_time, run_time, end_time;
    start_time = clock();

    int i, j, k;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            for (k = 0; k < size; k++)
            {
                C[i] += A[k] * B[j];
            }
        }
    }

    end_time = clock();
    run_time = end_time - start_time;

    return run_time / 1000;
}