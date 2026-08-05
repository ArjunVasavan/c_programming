#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t lock;
int var = 0;

void fun(void)
{
    pthread_mutex_lock(&lock);   // OK (recursive)
    var = 20;
    pthread_mutex_unlock(&lock);
}

void* thread_fun(void* arg)
{
    pthread_mutex_lock(&lock);
    var = 10;

    fun();   // second lock allowed

    printf("Thread %lu: var = %d\n", pthread_self(), var);
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

    pthread_create(&t, NULL, thread_fun, NULL);
    pthread_join(t, NULL);

    pthread_mutex_destroy(&lock);
    pthread_mutexattr_destroy(&attr);
    return 0;
}

