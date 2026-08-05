/*
    BASIC THREAD ATTRIBUTES EXAMPLE
    -------------------------------
    This program demonstrates:

    1. How to create a thread attribute object
    2. How to set detach state using attributes
    3. Difference between JOINABLE and DETACHED threads
*/

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

/*
   Thread function.
*/
void* thread_function(void* arg)
{
    printf("Thread started (ID = %lu)\n", pthread_self());

    sleep(2);   // simulate some work

    printf("Thread finished (ID = %lu)\n", pthread_self());

    return NULL;
}

int main()
{
    pthread_t tid;

    /*
       STEP 1: Declare thread attribute variable
    */
    pthread_attr_t attr;

    /*
       STEP 2: Initialize attribute variable
       This sets DEFAULT thread attributes.
    */
    pthread_attr_init(&attr);

    /*
       STEP 3: Modify ONE attribute
       Here we set the thread to DETACHED state.
       That means we CANNOT use pthread_join().
    */
    pthread_attr_setdetachstate(
        &attr,
        PTHREAD_CREATE_DETACHED
    );

    /*
       STEP 4: Create thread using attributes
    */
    pthread_create(&tid, &attr, thread_function, NULL);

    /*
       STEP 5: Destroy attribute object
       (thread has already copied the values)
    */
    pthread_attr_destroy(&attr);

    /*
       Since thread is DETACHED,
       we MUST NOT call pthread_join().
    */

    printf("Main thread finished\n");

    /*
       sleep() is used only so that
       detached thread gets time to run
       before process exits.
    */
    sleep(3);

    return 0;
}

