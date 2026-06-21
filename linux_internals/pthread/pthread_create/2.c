#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

void *say_hello(void *arg) {
    printf("Hello from thread! ID: %lu\n", pthread_self());
    return NULL;
}

int main() {
    pthread_t tid; // we created an thread ID

    int err = pthread_create(&tid, NULL, say_hello, NULL);
    if (err != 0) {
        printf("Error creating thread: %s\n", strerror(err));
        exit(1);
    }

    printf("Hello from main! ID: %lu\n", pthread_self());

    pthread_join(tid, NULL);
    return 0;
}
