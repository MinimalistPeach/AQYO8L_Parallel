#include <stdio.h>
#include "../Headers/RNG.h"

int main()
{

    int min, max;
    min = 500;
    max = 1000;

    float min_fl, max_fl;
    min_fl = 500.0;
    max_fl = 1000.0;

    int number;
    number = generateRandInt(min, max);
    float float_num;
    float_num = generateRandFloat(min_fl, max_fl);
    printf("Egesz veletlen szam: %d", number);
    printf("\nLebegopontos veletlen szam: %f", float_num);
    return 0;
}