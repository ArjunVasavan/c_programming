#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

void fun(void);

pthread_mutex_t lock;
int var = 0;

void* thread_fun(void* arg)
{
    while (1)
    {
        pthread_mutex_lock(&lock);

        var = 10;

        fun();   // second lock attempt from SAME thread

        printf("Thread %lu: var = %d\n", pthread_self(), var);

        pthread_mutex_unlock(&lock);

        sleep(1);
    }

    return NULL;
}

void fun(void)
{
    int ret = pthread_mutex_lock(&lock);

    if (ret != 0)
    {
        printf("Thread %lu tried to lock mutex again (ERRORCHECK caught it)\n",
               pthread_self());
        return;
    }

    var = 20;
    printf("Inside fun(): var = %d\n", var);

    pthread_mutex_unlock(&lock);
}

int main(int argc, char** argv)
{
    pthread_t thread1, thread2;
    pthread_mutexattr_t attr;

    pthread_mutexattr_init(&attr);

    // ERRORCHECK mutex
    pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_ERRORCHECK_NP);

    if (pthread_mutex_init(&lock, &attr) != 0)
    {
        printf("pthread mutex init failed\n");
        exit(EXIT_FAILURE);
    }

    pthread_create(&thread1, NULL, thread_fun, NULL);
    pthread_create(&thread2, NULL, thread_fun, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    pthread_mutex_destroy(&lock);
    pthread_mutexattr_destroy(&attr);

    return 0;
}

