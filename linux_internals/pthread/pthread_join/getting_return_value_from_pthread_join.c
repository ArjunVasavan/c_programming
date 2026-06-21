#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void *calculate(void *arg) {
    int *result = malloc(sizeof(int));  // heap allocate result
    *result = 42;
    return result;                      // return void*
}

int main() {
    pthread_t tid;
    void *retval;

    pthread_create(&tid, NULL, calculate, NULL);

    pthread_join(tid, &retval);         // capture return value

    int *result = (int*)retval;         // cast void* → int*
    printf("Thread returned: %d\n", *result);

    free(retval);                       // free heap memory
    return 0;
}
