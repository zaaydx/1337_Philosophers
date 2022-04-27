#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define COUNT_TO 10
#define MAX_CORES 5

static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
long long i = 0;

void *eating_routine(void *arg)
{
        pthread_mutex_lock(&mutex);
        printf("philo %lld is eating\n", i++);
        pthread_mutex_unlock(&mutex);
        return EXIT_SUCCESS;
}

int main(void)
{
    int i = 0;

    pthread_t *thread_group = malloc(sizeof(pthread_t) * MAX_CORES);

    for (i = 0; i <= MAX_CORES; ++i)
    {
        pthread_create(&thread_group[i], NULL, eating_routine, NULL);
    }

    for(i = 0; i <= MAX_CORES; ++i)
    {
        pthread_join(thread_group[i], NULL);
    }

    return (EXIT_SUCCESS);
}