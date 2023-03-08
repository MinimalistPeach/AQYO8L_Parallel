#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    
    int isPrime, max, primenumbers = 0;

    printf("Input a number larger than 999: ");
    scanf("%d", &max);

    printf("MAX: %d\n", max);
    clock_t start = clock();
    for (int i = 0; i < max; i++)
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
            clock_t end = clock();
            float seconds = (float)(end - start) / CLOCKS_PER_SEC;
            printf("\n running time: %f prime number count: %d", seconds, primenumbers);
        }
    }

    
}