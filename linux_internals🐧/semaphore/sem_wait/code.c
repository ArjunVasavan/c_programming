#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t sem;

void *thread_func(void *arg) {
    printf("Thread waiting...\n");
    sem_wait(&sem);                  // blocks here, count is 0
    printf("Thread got through!\n");
    return NULL;
}

int main() {
    sem_init(&sem, 0, 0);            // start at 0

    pthread_t t;
    pthread_create(&t, NULL, thread_func, NULL);

    sleep(2);                        // simulate doing some work
    printf("Main posting now\n");
    sem_post(&sem);                  // wake the thread up

    pthread_join(t, NULL);
    sem_destroy(&sem);
    return 0;
}
