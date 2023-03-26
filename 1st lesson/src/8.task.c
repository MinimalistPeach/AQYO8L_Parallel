#include <stdio.h>
#include <stdlib.h>
#include "filemanager.h"
#include "inputhandler.h"

int main()
{
    int count[1];
    printf("Mennyi random szamot irjunk fajlokba? ");
    getIntegerInput(count, 1, 1, 12000);
    long int result = writeRandFloatToFile(count[0]);
    if (result > 0)
    {
        printf("Float-ok fajlba irasa sikeres! Fajlmerete: %ld byte.\n", result);
    }
    result = writeRandIntToFile(count[0]);
    if (result > 0)
    {
        printf("Integerek fajlba irasa sikeres! Fajlmerete: %ld byte.\n", result);
    }

    result = writeRandLongToFile(count[0]);
    if (result > 0)
    {
        printf("Long-ok fajlba irasa sikeres! Fajlmerete: %ld byte.\n", result);
    }

    if(result == 0)
    {
        printf("Fajlbairas hiba!\n");
    }

    getchar();
    return 0;
}