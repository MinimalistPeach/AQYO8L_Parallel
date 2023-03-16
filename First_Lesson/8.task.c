#include <stdio.h>
#include <stdlib.h>
#include "../Headers/FileManager.h"

int readIn();

int readIn()
{
    int count, number_of_inputs, ok;

    do
    {
        ok = 1;
        number_of_inputs = scanf("%d", &count);
        if (number_of_inputs != 1)
        {
            ok = 0;
            printf("1 szamot szukseges megadni!\n");
            while (getchar() != '\n');
        }
        else if (count < 0)
        {
            printf("Pozitiv darabszamot lehet csak megadni!!\n");
            ok = 0;
        }
    } while (!ok);

    return count;
}

int main()
{
    printf("Mennyi random szamot irjunk fajlokba? ");
    int count = readIn();
    long int result = writeRandFloatToFile(count);
    if (result > 0)
    {
        printf("Float-ok fajlba irasa sikeres! Fajlmerete: %ld byte.\n", result);
    }
    result = writeRandIntToFile(count);
    if (result > 0)
    {
        printf("Integerek fajlba irasa sikeres! Fajlmerete: %ld byte.\n", result);
    }

    result = writeRandLongToFile(count);
    if (result > 0)
    {
        printf("Long-ok fajlba irasa sikeres! Fajlmerete: %ld byte.\n", result);
    }

    if(result == 0)
    {
        printf("Fajlbairas hiba!\n");
    }
    /*int i;
    int *arr = readIntFromFile(count);
    if(arr) {
        for(i = 0; i < count; i++)
        {
            //printf("%d\n", arr[i]);
        }
        free(arr);
    }*/
    getchar();
    return 0;
}