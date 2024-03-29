#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "xlsxwriter.h"

int main()
{

    lxw_workbook  *workbook  = workbook_new("7task.xlsx");
    lxw_worksheet *worksheet = workbook_add_worksheet(workbook, NULL);
    int row = 1, col = 0;
    worksheet_write_string(worksheet, 0, col, "run time", NULL);
    worksheet_write_string(worksheet, 0, col+1, "prime number count", NULL);

    
    int isPrime, max, primenumbers = 0;

    printf("Input a number larger than 999: ");
    scanf("%d", &max);

    //printf("MAX: %d\n", max);
    time_t start;
    start = time(0);
    int i;
    for (i = 0; i < max; i++)
    {
        
        if (i > 1)
        {
            isPrime = 1;
            for (int j = 2; j <= i / 2; ++j)
            {

                if (i % j == 0)
                {
                    isPrime = 0;
                    break;
                }
            }
        }
        if(isPrime) primenumbers++;
        if (i % 1000 == 0)
        {
            time_t end;
            end = time(0);
            float seconds = (float)(end - start) / CLOCKS_PER_SEC;
            printf("\n run time: %f prime number count: %d", seconds, primenumbers);
            worksheet_write_number(worksheet, row, col,     seconds, NULL);
            worksheet_write_number(worksheet, row, col + 1, primenumbers, NULL);
            row++;
        }
    }

    return workbook_close(workbook);

    
}