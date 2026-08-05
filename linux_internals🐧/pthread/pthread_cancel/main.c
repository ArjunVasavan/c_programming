#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *worker(void *arg) {
    while (1) {
        printf("Thread working...\n");
        usleep(1);           // this is a cancellation point
    }
    return NULL;
}

int main() {
    pthread_t t;
    pthread_create(&t, NULL, worker, NULL);

    sleep(3);
    pthread_cancel(t);          // send cancel request
    pthread_join(t, NULL);      // wait for it to finish

    printf("Thread cancelled\n");
    return 0;
}
