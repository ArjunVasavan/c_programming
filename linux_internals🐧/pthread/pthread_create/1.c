#include <stdio.h>
#include <pthread.h>

void *func(void *arg) {
    printf("Thread running\n");
    return NULL;
}

int main() {
    pthread_t tid;
    pthread_create(&tid, NULL, func, NULL);
    printf("Main running\n");
    pthread_join(tid, NULL);
}

// Possible output 1:        Possible output 2:
// Main running              Thread running
// Thread running            Main running
// BOTH are valid!
