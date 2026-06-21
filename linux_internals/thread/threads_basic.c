/*
    BASIC THREAD EXAMPLE
    --------------------
    This program demonstrates:

    1. How to create threads
    2. How threads run concurrently
    3. How to wait for threads using pthread_join()
*/

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

/*
   Thread function.
   Every thread starts execution from here.
*/
void* thread_function(void* arg)
{
    int thread_num = *(int*)arg;

    /*
       pthread_self() gives the ID of
       the currently running thread.
    */
    printf("Thread %d started (ID = %lu)\n",
           thread_num, pthread_self());

    /*
       sleep() is used only to
       clearly see concurrency.
    */
    sleep(2);

    printf("Thread %d finished\n", thread_num);

    return NULL;
}

int main()
{
    pthread_t t1, t2;
    int id1 = 1;
    int id2 = 2;

    /*
       Create thread 1.
       Arguments:
       1. &t1         -> where thread ID is stored
       2. NULL        -> default attributes
       3. thread_function -> function thread runs
       4. &id1        -> argument passed to thread
    */
    pthread_create(&t1, NULL, thread_function, &id1);

    /*
       Create thread 2.
    */
    pthread_create(&t2, NULL, thread_function, &id2);

    /*
       pthread_join() makes the main thread WAIT
       until the specified thread finishes.
    */
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    /*
       This line executes only AFTER
       both threads have finished.
    */
    printf("Main thread: all threads finished\n");

    return 0;
}

