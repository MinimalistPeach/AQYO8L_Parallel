#ifndef PARALLELGENERATION_H
#define PARALLELGENERATION_H


#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <malloc.h>
#include <omp.h>
#include "rng.h"

double multiplyMatrixParallel(int **A, int **B, int **C, int size, int thread_num);

#endif /*PARALLELGENERATION_H*/