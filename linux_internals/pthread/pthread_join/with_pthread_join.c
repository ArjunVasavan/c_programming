#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *worker(void *arg) {
    sleep(2);
    printf("Thread done!\n");
    return NULL;
}

int main() {
    pthread_t tid;
    pthread_create(&tid, NULL, worker, NULL);
    printf("Main waiting...\n");
    pthread_join(tid, NULL);    // wait here
    printf("Main done!\n");
    return 0;
}

// Output:
// Main waiting...
// Thread done!     ← thread finishes first
// Main done!       ← then main continues
