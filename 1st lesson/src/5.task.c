#include <stdio.h>
#include <stdlib.h>
#include "rng.h"

int readIn();

int readIn()
{
    int min, max, number_of_inputs, ok;

    do
    {
        ok = 1;
        number_of_inputs = scanf("%d %d", &min, &max);
        if (number_of_inputs != 2)
        {
            ok = 0;
            printf("2 szamot szukseges megadni!\n");
            while (getchar() != '\n');
        }
        else if (min < 0)
        {

            printf("Pozitiv intervallumot lehet csak megadni!!\n");
            ok = 0;
        }
        else if (max < min)
        {

            printf("Az intervallum zaro elemenek nagyobbnak kell lennie mint a nyito elemnek!\n");
            ok = 0;
        }
    } while (!ok);

    int random = generateRandInt(min, max);

    return random;
}

int main()
{

    printf("Adja meg a minimum es a maximum erteket (pl: 2 5): ");
    int num;
    num = readIn();

    printf("A megadott intervallumon generalt random szam: %d", num);

    printf("\n");

    getchar();

    return 0;
}