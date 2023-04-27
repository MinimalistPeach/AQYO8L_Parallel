#include "bfs.h"

void *bfs_parallel(void *args)
{
    ThreadData *data = (ThreadData *)args;
    int i;
    for (i = data->start; i < data->end; i++)
    {
        data->nodes[i].visited = true;
    }
    return NULL;
}

double bfs_sequential(Node *nodes, int num_nodes)
{
    clock_t time;
    time = clock();
    int i;
    for (i = 0; i < num_nodes; i++)
    {
        nodes[i].visited = true;
    }
    double runtime;
    time = clock() - time;
    runtime = ((double)time) / CLOCKS_PER_SEC;

    return runtime;
}

int countVisitedNodes(Node *nodes, int num_nodes)
{
    int counter, i;
    counter = 0;

    for (i = 0; i < num_nodes; i++)
    {
        if (nodes[i].visited == 1)
        {
            counter += 1;
        }
    }
    return counter;
}

double startThreads(Node *nodes, int number_of_threads, int number_of_nodes)
{
    pthread_t *threads = malloc(sizeof(pthread_t) * number_of_nodes);
    ThreadData *thread_data = malloc(sizeof(ThreadData) * number_of_nodes);

    clock_t start = clock();
    for (int i = 0; i < number_of_threads; i++)
    {
        thread_data[i].start = i * (number_of_nodes / number_of_threads);
        thread_data[i].end = (i + 1) * (number_of_nodes / number_of_threads);
        thread_data[i].nodes = nodes;
        pthread_create(&threads[i], NULL, bfs_parallel, (void *)&thread_data[i]);
    }

    for (int i = 0; i < number_of_threads; i++)
    {
        pthread_join(threads[i], NULL);
    }

    clock_t end = clock();
    double runtime = ((double)(end - start)) / CLOCKS_PER_SEC;

    freeThreads(threads, thread_data, number_of_nodes);

    return runtime;
}

void freeThreads(pthread_t *threads, ThreadData *threaddata, int num_of_nodes)
{
 
    free(threads);
    free(threaddata);
}