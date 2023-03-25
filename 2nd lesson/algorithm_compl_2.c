#include <unistd.h>
#include <stdbool.h>
#include "../include/rng.h"
#include <stdio.h>
#include <windows.h>

void generateArray(int *array, int min, int max, int size);
void duplicateNumbers(int *array, int size);
bool isUnique(int *array, int size, int currentIndex);

int main()
{
    int size, min, max, i;
    LARGE_INTEGER start, end, frequency;
    double elapsed;

    printf("Mekkora tombbel dolgozzunk? ");
    if (scanf("%d", &size) != 1)
    {
        printf("Egy adatot kertem.");
    }
    int arr[size];

    printf("\nMilyen tartomanyon legyenek a tomb elemei? ");
    if (scanf("%d %d", &min, &max) != 2)
    {
        printf("Ketto adatot kertem.");
    }

    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&start);

    generateArray(arr, min, max, size);

    QueryPerformanceCounter(&end);
    elapsed = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;

    printf("\n%d elemnel %lf mp-be telt elkesziteni a tombot.", size, elapsed);

    printf("\n");

    for (i = 0; i < size; i++)
    {
        printf("%d egyedi? %s\n", arr[i], isUnique(arr, size, i) ? "igen" : "nem");
    }

    printf("\n");

    duplicateNumbers(arr, size);

    for (i = 0; i < size; i++)
    {
        printf("%d egyedi? %s\n", arr[i], isUnique(arr, size, i) ? "igen" : "nem");
    }


    return 0;
}

void generateArray(int *array, int min, int max, int size)
{
    int i;
    printf("\n");
    for (i = 0; i < size; i++)
    {
        array[i] = generateRandInt(min, max);
        printf("%d ", array[i]);
    }
}

void duplicateNumbers(int *array, int size)
{
    int i, chance;
    for (i = 0; i < size - 1; i++)
    {
        chance = generateRandInt(1, 2);
        switch (chance)
        {
        case 1:
            break;
        case 2:
            array[i + 1] = array[i];
            break;
        default:
            break;
        }
    }
}

bool isUnique(int *array, int size, int currentIndex)
{
    int i;
    bool unique;
    unique = true;

    for (i = 0; i < size; i++)
    {
        if (currentIndex != i)
        {
            if (array[currentIndex] == array[i])
            {
                unique = false;
                continue;
            }
        }
    }

    return unique;
}