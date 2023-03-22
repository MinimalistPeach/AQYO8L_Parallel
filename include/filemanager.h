#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "RNG.h"

long int writeRandFloatToFile(int count)
{
    FILE *fptr;
    fptr = fopen("Outputs/8.task_float.txt", "w");

    unsigned i;

    for (i = 0; i < count; i++)
    {
        fprintf(fptr, "%.5f\n", generateRandFloat(1, 20000 + i * 12));
    }

    fseek(fptr, 0L, SEEK_END);

    long int res = ftell(fptr);

    fclose(fptr);

    return res;
}

long int writeRandIntToFile(int count)
{
    FILE *fptr;
    fptr = fopen("Outputs/8.task_int.txt", "w");

    int i;
    for (i = 0; i < count; i++)
    {
        fprintf(fptr, "%d\n", generateRandInt(1, 20000 + i * 12));
    }

    fseek(fptr, 0L, SEEK_END);

    long int res = ftell(fptr);

    fclose(fptr);

    return res;
}

long int writeRandLongToFile(int count)
{
    FILE *fptr;
    fptr = fopen("Outputs/8.task_long.txt", "w");

    int i;
    for (i = 0; i < count; i++)
    {
        fprintf(fptr, "%d\n", generateRandLong(-1000, 19000 + i * 12));
    }

    fseek(fptr, 0L, SEEK_END);

    long int res = ftell(fptr);

    fclose(fptr);

    return res;
}

/*int *readIntFromFile(int count)
{
    FILE *fp;
    char c;
    char temp_c[6];
    int i = 0;
    int *arr = malloc(count);
    if (!arr)
        return NULL;

    fp = fopen("Outputs/8.task_int.txt", "r");

    if (fp == NULL)
    {
        return 0;
    }

    for (c = getc(fp); c != EOF; c = getc(fp))
    {
        if (c != '\n')
        {

            temp_c += c;
            printf("%c\n", temp_c);
            arr[i] = (int)c;
            i++;
        }
    }

    fclose(fp);

    return arr;
}*/