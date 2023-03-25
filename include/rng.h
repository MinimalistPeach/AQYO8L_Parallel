#include <time.h>
#include <stdlib.h>
#include <windows.h>


int generateRandInt(int min, int max)
{
    srand((unsigned) rand());
    int number;
    number = rand() % (max - min + 1) + min;

    return number;
}

float generateRandFloat(float min, float max)
{
    srand(time(NULL));
    float number;
    number = (float)rand() / RAND_MAX * (max - min) + min;
    return number;
}

int generateRandLong(long min, long max)
{
    srand(time(NULL));
    long number;
    number = rand() % (max - min + 1) + min;

    return number;
}