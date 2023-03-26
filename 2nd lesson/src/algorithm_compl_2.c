#include <unistd.h>
#include <stdbool.h>
#include "rng.h"
#include "inputhandler.h"
#include <stdio.h>
#include <windows.h>

void generateArray(int *array, int min, int max, int size);
void duplicateNumbers(int *array, int size);
bool isUnique(int *array, int size, int currentIndex);

int main()
{
    int min, max, i;
    LARGE_INTEGER start, end, frequency;
    double elapsed;
    int range[2];
    int size[1];

    printf("Mekkora tombbel dolgozzunk? ");
    getIntegerInput(size, 1, 1, 200);
    int arr[size[0]];

    printf("\nMilyen tartomanyon legyenek a tomb elemei? ");
    printf("\nEloszor a minimum elemet kell megadni, majd a maximumot. ");
    getIntegerInput(range, 2, 1, 250000);

    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&start);

    generateArray(arr, range[0], range[1], size[0]);

    QueryPerformanceCounter(&end);
    elapsed = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;

    printf("\n%d elemnel %lf mp-be telt elkesziteni a tombot.", size[0], elapsed);

    printf("\n");

    for (i = 0; i < size[0]; i++)
    {
        printf("%d egyedi? %s\n", arr[i], isUnique(arr, size[0], i) ? "igen" : "nem");
    }

    printf("\n");

    printf("Szamok duplikalas 0.5 esellyel.\n");
    duplicateNumbers(arr, size[0]);

    for (i = 0; i < size[0]; i++)
    {
        printf("%d egyedi? %s\n", arr[i], isUnique(arr, size[0], i) ? "igen" : "nem");
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