#include "rng.h"

int generateRandInt(int min, int max)
{
    srand(rand());

    int num;

    num = rand() % max + min;

    return num;
}