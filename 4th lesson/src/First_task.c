#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include "rng.h"
#include "inputhandler.h"

int main()
{
    int size[1], i;
    printf("Hany elemet tartalmazzon a tomb?\n");
    getIntegerInput(size, 1, 1, 10);
    double array[size[0]], result, partial_result, full_result;
    result = 1;

    for (i = 0; i < size[0]; i++)
    {
        array[i] = generateRandDouble(1, 1000);
        result *= array[i];
        printf("%lf ", array[i]);
    }
    printf("\n%lf", result);

    #pragma omp parallel private(partial_result) shared(full_result)
    {
        partial_result = 0;
        full_result = 0;

        #pragma omp for
        {
            for (int j = 1; j <= 1000; j++)
            {
                partial_result += array[j];
            }
        }

        #pragma omp critical
        {
            full_result += partial_result;
        }
    }
    printf(" \n%lf ", full_result);
}