#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define NUM_THREADS 4

void *worker(void *arg) {
    int id = *(int*)arg;
    free(arg);
    printf("Thread %d working\n", id);
    return NULL;
}

int main() {
    pthread_t tids[NUM_THREADS];

    // Create all threads
    for (int i = 0; i < NUM_THREADS; i++) {
        int *id = malloc(sizeof(int));
        *id = i;
        pthread_create(&tids[i], NULL, worker, id);
    }

    // Join all threads — wait for ALL to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(tids[i], NULL);
        printf("Thread %d joined\n", i);
    }

    printf("All threads done!\n");
    return 0;
}
