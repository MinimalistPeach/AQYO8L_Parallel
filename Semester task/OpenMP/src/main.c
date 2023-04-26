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
        printf("Szukseges legalabb 1 parameter, amiben a matrix meretet adjuk meg!!");
        printf("\nRoviditett hasznalat: matrix_mult.exe <szalak szama>");
        printf("\nHasznalat: matrix_mult.exe <1.matrix nagysaga> .... <n.matrix nagysaga> <szalak szama>");
        return 0;
    }

    for (i = 1; i < argc - 1; i++)
    {
        size = atoi(argv[i]);
        int **A = (int **)malloc(size * sizeof(int *));
        int **B = (int **)malloc(size * sizeof(int *));
        int **C = (int **)malloc(size * sizeof(int *));

        generateMatrix((int **)A, (int **)B, (int **)C, size);

        double parallel_time = multiplyMatrixParallel((int **)A, (int **)B, (int **)C, size, num_threads);

        printf("%dx%d nagysagu matrixok szorzasanak futasi ideje parhuzamosan: %f mp\n", size, size, parallel_time);

        double sequential_time = multiplyMatrixSeq((int **)A, (int **)B, (int **)C, size);

        printf("%dx%d nagysagu matrixok szorzasanak futasi ideje szekvencialisan: %f mp\n", size, size, sequential_time);

        freeMemory((int **)A, (int **)B, (int **)C, size);
    }

    return 0;
}
