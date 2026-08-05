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
    // NO pthread_join()
    printf("Main done!\n");
    return 0;   // main exits → ALL threads killed!
}

// Output:
// Main done!
// "Thread done!" never prints!
// thread was killed before it could finish
