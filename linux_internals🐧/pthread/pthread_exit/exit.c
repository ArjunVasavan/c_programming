#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void *worker(void *arg) {
    int *result = malloc(sizeof(int));
    *result = 100;
    pthread_exit(result);           // exits thread, passes value
}

int main() {
    pthread_t t;
    void *retval;

    pthread_create(&t, NULL, worker, NULL);
    pthread_join(t, &retval);       // waits + collects return value

    printf("Got: %d\n", *(int *)retval);
    free(retval);                   // you must free it
    return 0;
}
