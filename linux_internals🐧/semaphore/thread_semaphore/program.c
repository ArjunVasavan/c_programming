#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

int var = 0;

int count;
sem_t sem_token;

void* thread_fun(void* arg) {

    while(1) {

        sem_wait(&sem_token);

        count = 0;

        count+=5;

        count+=10;

        printf("%d\n",count);

        sem_post(&sem_token);

    }

    return NULL;
}

int main() {
    pthread_t t1,t2;

    sem_init(&sem_token,0,1);

    // DEFAULT mutex

    pthread_create(&t1, NULL, thread_fun, NULL);
    pthread_create(&t2, NULL, thread_fun, NULL);
    pthread_join(t1, NULL);

    return 0;
}

