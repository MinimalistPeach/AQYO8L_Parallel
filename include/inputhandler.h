#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int getOneIntInput(int min, int max)
{
    int out, number_of_inputs;
    bool ok;

    do
    {
        ok = true;
        number_of_inputs = scanf("%d", &out);
        if (number_of_inputs != 1)
        {
            ok = false;
            printf("1 szamot kell megadni!\n");
            while (getchar() != '\n')
                ;
        }
        else if (out < min)
        {

            printf("A szam nem lehet kisebb %d-nel.\n", min);
            ok = 0;
        }
        else if (out > max)
        {

            printf("A szam nem lehet nagyobb %d-nel.\n", max);
            ok = 0;
        }
    } while (!ok);
}

void getIntegerInput(int *arr, int count, int min, int max)
{
    int i, num_of_inputs;
    bool ok;
    do
    {
        ok = true;

        for (i = 0; i < count; i++)
        {
            num_of_inputs = scanf("%d", &arr[i]);
            if (num_of_inputs != 1)
            {
                printf("Egyszerre egy elemet lehet megadni!");
                ok = false;
                break;
            }
            else if (arr[i] < min)
            {
                printf("A szam nem lehet kisebb %d-nel.\n", min);
                ok = false;
                break;
            }
            else if (arr[i] > max)
            {

                printf("A szam nem lehet nagyobb %d-nel.\n", max);
                ok = false;
                break;
            }
            else if (arr[0] > arr[count-1])
            {
                printf("\nA minimumnak kisebbnek kell lennie a maximumnal!");
                ok = false;
                break;
            }
        }

        while (getchar() != '\n');

    } while (!ok);
}

#endif /* INPUTHADLDER_H */