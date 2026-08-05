#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t sem;

void *thread_func(void *arg) {
    int id = *(int *)arg;
    printf("Thread %d waiting...\n", id);
    sem_wait(&sem);
    printf("Thread %d got through!\n", id);
    return NULL;
}

int main() {
    sem_init(&sem, 0, 0);       // count = 0, all threads will block

    pthread_t t[3];
    int ids[3] = {1, 2, 3};

    for (int i = 0; i < 3; i++) {
        pthread_create(&t[i], NULL, thread_func, &ids[i]);
    }

    sleep(1);

    printf("Main posting 3 times...\n");
    sem_post(&sem);             // wakes thread 1
    sem_post(&sem);             // wakes thread 2
    sem_post(&sem);             // wakes thread 3

    for (int i = 0; i < 3; i++) {
        pthread_join(t[i], NULL);
    }

    sem_destroy(&sem);
    return 0;
}
