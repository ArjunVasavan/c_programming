#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int counter = 0;

void* increment(void* arg) {
    for(int i = 0; i < 5; i++) {
        pthread_mutex_lock(&mutex);     // Lock

        // Critical section
        counter++;
        printf("Thread %ld: counter = %d\n", pthread_self(), counter);

        pthread_mutex_unlock(&mutex);   // Unlock

        usleep(100000);                 // 100ms delay
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;

    // Create threads
    pthread_create(&t1, NULL, increment, NULL);
    pthread_create(&t2, NULL, increment, NULL);

    // Wait for threads to finish
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    // Cleanup
    pthread_mutex_destroy(&mutex);

    printf("Final counter: %d\n", counter);
    return 0;
}

