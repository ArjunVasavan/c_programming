#include <stdio.h>
#include <pthread.h>

pthread_mutex_t lock;
int value = 0;

void inner()
{
    pthread_mutex_lock(&lock);
    value += 10;
    pthread_mutex_unlock(&lock);
}

void* worker(void* arg)
{
    pthread_mutex_lock(&lock);
    value += 1;

    inner();   // same thread locks again (allowed)

    pthread_mutex_unlock(&lock);
    return NULL;
}

int main()
{
    pthread_t t;
    pthread_mutexattr_t attr;

    pthread_mutexattr_init(&attr);
    pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
    pthread_mutex_init(&lock, &attr);

    pthread_create(&t, NULL, worker, NULL);
    pthread_join(t, NULL);

    pthread_mutex_destroy(&lock);
    pthread_mutexattr_destroy(&attr);

    printf("value = %d\n", value);
    return 0;
}

