/*
    BASIC MUTEX EXAMPLE
    -------------------
    This program demonstrates:

    1. What a mutex is
    2. Why it is needed
    3. How to protect shared data
*/

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

/* 
   Shared data.
   This variable is accessed by multiple threads.
*/
int counter = 0;

/*
   Mutex declaration.
   This mutex will protect 'counter'.
*/
pthread_mutex_t lock;

/*
   Thread function.
   Each thread will increment 'counter'.
*/
void* thread_function(void* arg)
{
    /*
       LOCK the mutex before accessing shared data.
       If another thread already holds the lock,
       this thread will WAIT here.
    */
    pthread_mutex_lock(&lock);

    /*
       CRITICAL SECTION
       ----------------
       Only ONE thread can execute this block at a time.
    */
    counter++;
    printf("Thread %lu incremented counter to %d\n",
           pthread_self(), counter);

    /*
       UNLOCK the mutex after finishing shared work.
       This allows another thread to enter.
    */
    pthread_mutex_unlock(&lock);

    return NULL;
}

int main()
{
    pthread_t t1, t2;

    /*
       Initialize the mutex.
       NULL => default mutex type.
    */
    pthread_mutex_init(&lock, NULL);

    /*
       Create two threads.
       Both will run thread_function().
    */
    pthread_create(&t1, NULL, thread_function, NULL);
    pthread_create(&t2, NULL, thread_function, NULL);

    /*
       Wait for both threads to finish.
    */
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    /*
       Destroy the mutex.
       Should be done when mutex is no longer needed.
    */
    pthread_mutex_destroy(&lock);

    /*
       Final value of counter.
       Guaranteed to be correct because of mutex.
    */
    printf("Final counter value = %d\n", counter);

    return 0;
}

