#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "handleinput.h"


int getOneIntInput(int min, int max, int numOfSpace)
{
    int out, number_of_inputs;
    bool ok;
    numOfSpace = 0;

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

    if(out >= 10)
    {
        numOfSpace = 1;
    }
    if(out >= 100)
    {
        numOfSpace = 2;
    }
    if(out >= 1000)
    {
        numOfSpace = 3;
    }

    return out;
}