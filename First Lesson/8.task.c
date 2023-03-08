#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARR_SIZE 7

void writeInt_ToFile(FILE **fptr);
void writeLong_ToFile(FILE **fptr);
void writeFloat_ToFile(FILE **fptr);

int main()
{
    FILE *fptr;
    writeInt_ToFile(&fptr);
    writeLong_ToFile(&fptr);
    writeFloat_ToFile(&fptr);

    getchar();
    return 0;
}

void writeInt_ToFile(FILE **fptr)
{
    int arr[ARR_SIZE] = {1, 2, 3, 4, 8, 53435, 24422};

    if (*fptr == NULL)
    {
        printf("File eleresi utvonala ures!");
        exit(1);
    }


    fptr = fopen("8.task_int.txt", "w");

    for (int i = 0; i < ARR_SIZE; i++)
    {
        fprintf(fptr, "%d, ", arr[i]);
    }

    fclose(fptr);
    printf("INT szamok kiirasa sikeres! Nyomjon ENTER-t a tovabblepeshez!");
    getchar();
}

void writeLong_ToFile(FILE **fptr)
{
    long arr[ARR_SIZE] = {19835878, 2, 3, -4121313, 8, 53435, 24422};

    if (*fptr == NULL)
    {
        printf("File eleresi utvonala ures!");
        exit(1);
    }


    fptr = fopen("8.task_long.txt", "w");

    for (int i = 0; i < ARR_SIZE; i++)
    {
        fprintf(fptr, "%d, ", arr[i]);
    }

    fclose(fptr);
    printf("LONG szamok kiirasa sikeres! Nyomjon ENTER-t a tovabblepeshez!");
    getchar();
}

void writeFloat_ToFile(FILE **fptr)
{
    float arr[ARR_SIZE] = {19878.20222, 2.1, 3.005, -41313.12, 8.7584, 5345.00001, 24422.1212};

    if (*fptr == NULL)
    {
        printf("File eleresi utvonala ures!");
        exit(1);
    }


    fptr = fopen("8.task_float.txt", "w");

    for (unsigned i = 0; i < ARR_SIZE; i++)
    {
        fprintf(fptr, "%.5f, ", arr[i]);
    }

    fclose(fptr);
    printf("FLOAT szamok kiirasa sikeres! Nyomjon ENTER-t a tovabblepeshez!");
    getchar();
}