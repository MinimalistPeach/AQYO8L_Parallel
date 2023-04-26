#ifndef PARALLELGENERATION_H
#define PARALLELGENERATION_H


#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <malloc.h>
#include <omp.h>
#include "rng.h"

void generateMatrix(int **A, int **B, int **C, int size);

double multiplyMatrix(int **A, int **B, int **C, int size);

void freeMemory(int **A, int **B, int **C, int size);


#endif /*PARALLELGENERATION_H*/