#include <stdio.h>
#include <pthread.h>

void *worker(void *arg) {
    pthread_t id = pthread_self();
    printf("I am thread: %lu\n", (unsigned long)id);
    return NULL;
}

int main() {
    pthread_t t1, t2;

    pthread_create(&t1, NULL, worker, NULL);
    pthread_create(&t2, NULL, worker, NULL);

    printf("Main thread: %lu\n", (unsigned long)pthread_self());

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    return 0;
}
