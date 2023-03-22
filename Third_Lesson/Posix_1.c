#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *secondary_thread(void *vargp)
{
    time_t start_time = time(NULL);
    while (time(NULL) - start_time < 4)
    {
        printf("\nMasodik szal fut %d masodperce", time(NULL) - start_time);

        sleep(1);
    }
    return NULL;
}

void main_thread()
{
    time_t start_time = time(NULL);
    while (time(NULL) - start_time < 8)
    {
        printf("\nElso szal fut %d masodperce", time(NULL) - start_time);

        sleep(1);
    }
}

int main()
{
    pthread_t thread_id;
    printf("Fo szal es masodik szal inditasa\n");
    pthread_create(&thread_id, NULL, secondary_thread, NULL);
    main_thread();
    printf("\nMasodik szal lelovese");
    pthread_join(thread_id, NULL);
    printf("\nSzalak befejezve! Nyomjon ENTER-t a programbol kilepeshez.");
    getchar();
    exit(0);
}
