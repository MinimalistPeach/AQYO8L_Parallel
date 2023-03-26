#include <stdio.h>
#include <stdlib.h>
#include "rng.h"
#include "inputhandler.h"

int main()
{
    int range[2];

    printf("Adja meg a minimum es a maximum erteket (pl: 2 5): ");
    getIntegerInput(range, 2, 1, 125000);

    printf("A megadott intervallumon generalt random szam: %d", generateRandInt(range[0], range[1]));

    printf("\n");

    getchar();

    return 0;
}