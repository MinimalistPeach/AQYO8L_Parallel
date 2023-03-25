#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <windows.h>

void *secondary_thread(void *vargp)
{
    printf("%d.szal elinditva\n", (int*)vargp);

    return NULL;
}

int main()
{
    pthread_t thread_id;
    int num = 60;
    int i;
    printf("%d szal elinditasa\n", num);
    for (i = 0; i < num; i++)
    {
        pthread_create(&thread_id, NULL, secondary_thread, i + 1);
    }

    printf("\nSzalak lelovese\n");
    for (i = 0; i < num; i++)
    {
        pthread_join(thread_id, NULL);
    }
    printf("\nSzalak befejezve! Nyomjon ENTER-t a programbol kilepeshez.");
    getchar();
    exit(0);
}
