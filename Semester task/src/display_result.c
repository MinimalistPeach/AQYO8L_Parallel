#include <stdio.h>
#include <stdlib.h>

#include "display_result.h"

void printOutRes(int A[][N], int B[][N], int C[][N], int n, int numOfSpace)
{
    int i, j, k;
    for (i = 0; i < n; i++)
    {
        for (k = 1; k < n * 2 + 6; k++)
        {
            printf(" ");
        }
        for (j = 0; j < n; j++)
        {
            if (j == 0)
            {
                printf("|");
                for(k = 0; k < numOfSpace; k++)
                {
                    printf(" ");
                }

            }
            printf("%d ", B[i][j]);
            if (j == n - 1)
            {
                for(k = 0; k < numOfSpace; k++)
                {
                    printf(" ");
                }
                printf("|");
            }
        }
        printf("\n");
    }
    printOutA(A, n, numOfSpace);
}

void printOutA(int A[][N], int n, int numOfSpace)
{
    int i, j, k;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (j == 0)
            {
                printf("|");
                for(k = 0; k < numOfSpace; k++)
                {
                    printf(" ");
                }
            }
            printf("%d ", A[i][j]);
            if (j == n - 1)
            {
                for(k = 0; k < numOfSpace; k++)
                {
                    printf(" ");
                }
                printf("|");
            }
        }
        printf("\n");
    }
}