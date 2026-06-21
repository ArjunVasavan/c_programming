#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

sem_t sem;

/* NOTE: Deadlock
 * thread is frozen at sem_wait, waiting for post
 * main is frozen at pthread_join, waiting for thread
 * sem_post is in the thread but below sem_wait — never reached
 * DEADLOCK Happened
 */

void *thread_func(void *arg) {
    printf("Thread waiting...\n");
    sem_wait(&sem);                  // blocks here, count is 0
    printf("Thread got through!\n");
    sem_post(&sem);                  // wake the thread up
    return NULL;
}

int main() {
    sem_init(&sem, 0, 0);            // start at 0

    pthread_t t;
    pthread_create(&t, NULL, thread_func, NULL);

    sleep(2);                        // simulate doing some work
    printf("Main posting now\n");

    pthread_join(t, NULL);
    sem_destroy(&sem);
    return 0;
}
