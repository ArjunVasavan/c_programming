#include <stdio.h>
#include <pthread.h>

pthread_mutex_t lock;
int counter = 0;

void* worker(void* arg)
{
    for (int i = 0; i < 100000; i++) {
        pthread_mutex_lock(&lock);
        counter++;
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

int main()
{
    pthread_t t1, t2;

    // DEFAULT mutex
    pthread_mutex_init(&lock, NULL);

    pthread_create(&t1, NULL, worker, NULL);
    pthread_create(&t2, NULL, worker, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_mutex_destroy(&lock);

    printf("counter = %d\n", counter);
    return 0;
}

