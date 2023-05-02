#include "matrix.h"

void generateMatrix(int *A, int *B, int *C, int size)
{
    for (int i = 0; i < size; i++)
    {
        A[i] = (int)malloc(size * sizeof(int *));
        B[i] = (int)malloc(size * sizeof(int *));
        C[i] = (int)malloc(size * sizeof(int *));
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            A[i] = i + j;
            B[i] = i - j;
            C[i] = 0.0;
        }
    }
}

void freeMemory(int *A, int *B, int *C, int size)
{
     for (int i = 0; i < size; i++) {
        free(&(A[i]));
        free(&(B[i]));
        free(&(C[i]));
    }
}