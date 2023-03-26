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

long int writeRandLettersToFile(int count)
{
    FILE *fptr;
    fptr = fopen("outputs/randomChars.txt", "w");

    if (fptr == NULL)
    {
        return -200;
    }

    int i, type, index;
    char c[64] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz 0123456789\n";
    for (i = 0; i < count; i++)
    {
        fputc(c[generateRandInt(0, 64)], fptr);
    }
    fseek(fptr, 0L, SEEK_END);

    long int res = ftell(fptr);
 
    fclose(fptr);

    return res;
}

int countLinesInFile(char *filename)
{
    FILE *fptr = fopen(filename, "r");
    if (fptr == NULL)
    {
        return -200;
    }
    int num_lines;
    num_lines = 1;
    char ch;

    while((ch = fgetc(fptr)) != EOF)
    {
        if(ch == '\n')
        {
            num_lines++;
        }
    }
    fclose(fptr);

    return num_lines;
}