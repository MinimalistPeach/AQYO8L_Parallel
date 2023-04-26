#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parallelgeneration.h"
#include "rng.h"
#include "matrix.h"
#include "parallelgeneration.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    int size;
    if(argc == 2)
    {
        size = atoi(argv[1]);
    }
    else {
        printf("Szukseges 1 parameter, amiben a matrix meretet adjuk meg!!");
        return 0;
    }

    int **A = (int **)malloc(size * sizeof(int *));
    int **B = (int **)malloc(size * sizeof(int *));
    int **C = (int **)malloc(size * sizeof(int *));

    generateMatrix((int**)A, (int**)B, (int**)C, size);

    double parallel_time = multiplyMatrix((int**)A, (int**)B, (int**)C, size);

    printf("Parhuzamos matrix szorzas futasi ideje: %f\n", parallel_time);

    freeMemory((int**)A, (int**)B, (int**)C, size);
    return 0;
}
