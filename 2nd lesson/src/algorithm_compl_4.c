#include <unistd.h>
#include <stdbool.h>
#include "filemanager.h"
#include "inputhandler.h"
#include <stdio.h>


int main()
{
    int count[1], num_of_lines;
    long int res;
    printf("Mennyi karaktert irjunk a fajlba? ");
    getIntegerInput(count, 1, 1, 300);
    res = writeRandLettersToFile(count[0]);

    if(res == -200)
    {
        printf("\nA fajlt nem sikerult letrehozni! :(\n");
        return -1;

    }

    printf("Fajlbairas sikeres! Az outputs mappaba talalhato meg a fajl. Merete: %ld byte.", res);

    num_of_lines = countLinesInFile("outputs/randomChars.txt");

    if(num_of_lines > 0)
    {
        printf("\nA fajlban %d sor talalhato.", num_of_lines);
    }

    return 0;
}