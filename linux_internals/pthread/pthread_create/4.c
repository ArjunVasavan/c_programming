#include <stdio.h>
#include <string.h>
#include <pthread.h>

typedef struct {
    int id;
    char name[50];
    int score;
} thread_args;

void *worker(void *arg) {
    thread_args *data = (thread_args*)arg;

    printf("Thread %d: name=%s score=%d\n",
           data->id, data->name, data->score);

    return NULL;
}

int main() {
    pthread_t tid;

    /* NOTE: New Way of passing on struct
     * using .field 
     */

    thread_args args = {
        .id    = 1,
        .score = 95
    };
    strcpy(args.name, "Arjun");

    pthread_create(&tid, NULL, worker, &args);
    pthread_join(tid, NULL);

    return 0;
}
