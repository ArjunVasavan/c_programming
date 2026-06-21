#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define NUM_THREADS 4

void *worker(void *arg) {
    int id = *(int*)arg;
    free(arg);   // free heap memory
    printf("Thread %d running\n", id);
    return NULL;
}

int main() {
    pthread_t tids[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        // heap allocate — so each thread gets its own copy
        int *id = malloc(sizeof(int));
        *id = i;
        pthread_create(&tids[i], NULL, worker, id);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(tids[i], NULL);
    }

    return 0;
}
