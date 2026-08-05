#include <stdio.h>
#include <pthread.h>

void *print_num(void *arg) {
    int num = *(int*)arg;    // cast void* → int*  then dereference
    printf("Thread got number: %d\n", num);
    return NULL;
}

int main() {
    pthread_t tid;
    int num = 42;

    pthread_create(&tid, NULL, print_num, &num);
    pthread_join(tid, NULL);

    return 0;
}
