#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t lock;
int var = 0;

void fun(void)
{
    // second lock attempt (SAME thread)
    pthread_mutex_lock(&lock);   // DEADLOCK here
    var = 20;
    pthread_mutex_unlock(&lock);
}

void* thread_fun(void* arg)
{
    pthread_mutex_lock(&lock);
    var = 10;

    fun();   // tries to lock again

    printf("Thread %lu: var = %d\n", pthread_self(), var);
    pthread_mutex_unlock(&lock);

    return NULL;
}

int main()
{
    pthread_t t;

    // DEFAULT mutex
    pthread_mutex_init(&lock, NULL);

    pthread_create(&t, NULL, thread_fun, NULL);
    pthread_join(t, NULL);

    pthread_mutex_destroy(&lock);
    return 0;
}

