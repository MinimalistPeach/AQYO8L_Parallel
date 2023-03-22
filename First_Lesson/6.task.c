#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "../include/rng.h"

#define MAX 20000

int main()
{
    int ok, input, sum;

    int random[2];
    random[0] = generateRandInt(1, MAX);
    sleep(1);
    random[1] = generateRandInt(1, MAX);

    sum = random[0] + random[1];

    printf("Mennyi %d+%d? ", random[0], random[1]);

    time_t start;
    time_t end;
    double execution_time;
    start = time(0);

    do
    {
        ok = 1;

        if (scanf("%d", &input) == 1)
        {

            if (input == sum)
            {
                ok = 1;
            }
            else
            {
                ok = 0;
                printf("\nA megoldas helytelen! Mas eredmeny: ");
            }
        }
        else
        {
            ok = 0;
            printf("Egy megoldast kerek csak!! Masik megoldas: ");
        }

    } while (!ok);

    end = time(0);

    execution_time = ((double)(end - start));
    printf("\nHelyes megoldas! A feladat %f masodpercbe telt! ", execution_time);

    printf("\n");

    getchar();

    return 0;
}