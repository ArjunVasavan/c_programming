#include <stdio.h>
#include <pthread.h>

pthread_mutex_t lock;

void inner()
{
    int ret = pthread_mutex_lock(&lock);
    if (ret != 0) {
        printf("ERRORCHECK: double lock detected\n");
        return;
    }
    pthread_mutex_unlock(&lock);
}

void* worker(void* arg)
{
    pthread_mutex_lock(&lock);
    inner();   // mistake: second lock attempt
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main()
{
    pthread_t t;
    pthread_mutexattr_t attr;

    pthread_mutexattr_init(&attr);
    pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_ERRORCHECK);
    pthread_mutex_init(&lock, &attr);

    pthread_create(&t, NULL, worker, NULL);
    pthread_join(t, NULL);

    pthread_mutex_destroy(&lock);
    pthread_mutexattr_destroy(&attr);
    return 0;
}

