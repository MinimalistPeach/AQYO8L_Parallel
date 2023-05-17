#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parallelgeneration.h"
#include "rng.h"
#include "matrix.h"
#include "sequentialgeneration.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    int size, num_threads, i;
    if (argc >= 3)
    {
        num_threads = atoi(argv[argc - 1]);
    }
    else
    {
        printf("\nHasznalat: matrix_mult.exe <1.matrix nagysaga> .... <n.matrix nagysaga> <szalak szama>");
        return 0;
    }

    for (i = 1; i < argc; i++)
    {
        size = atoi(argv[i]);
        int *A = malloc(size * sizeof(int *));
        int *B = malloc(size * sizeof(int *));
        int *C = malloc(size * sizeof(int *));

        generateMatrix((int *)A, (int *)B, (int *)C, size);

        double parallel_time = multiplyMatrixParallel((int *)A, (int *)B, (int *)C, size, num_threads);

        printf("\n%dx%d nagysagu matrixok szorzasanak futasi ideje parhuzamosan, %d szalon: %f mp\n", size, size, num_threads, parallel_time);

        double sequential_time = multiplyMatrixSeq((int *)A, (int *)B, (int *)C, size);

        printf("%dx%d nagysagu matrixok szorzasanak futasi ideje szekvencialisan: %f mp\n", size, size, sequential_time);
        printf("Szekvencialis es parhuzamos futasi ido kulonbsege %dx%d matrix eseten: %f mp\n", size, size, fabs(sequential_time - parallel_time));
    }


    return 0;
}
