/*
--------------------------------------------------------------------------------
Name : Arjun Vasavan

Date : 10/01/2026

Description : Program to find sum and maximum of a given array using multiple 
              threads. Synchronize threads using mutex

--------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int global_sum = 0;
int global_max = 0;
pthread_mutex_t lock;

typedef struct {
    int start;
    int end;
    int *array;
} container;

void update_global(int local_sum, int local_max)
{

    global_sum += local_sum;
    if (local_max > global_max)
        global_max = local_max;

}

void* sum_and_max(void *arg)
{
    container *c = (container *)arg;

    int local_sum = 0;
    int local_max = c->array[c->start];

    for (int i = c->start; i < c->end; i++) {
        local_sum += c->array[i];
        if (c->array[i] > local_max)
            local_max = c->array[i];
    }

    pthread_mutex_lock(&lock);
    update_global(local_sum, local_max);
    pthread_mutex_unlock(&lock);

    return NULL;
}

int main(void)
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    if (n < 5) {
        printf("Array size must be at least 5\n");
        return 1;
    }

    int *array = malloc(n * sizeof(int));
    if (!array) {
        perror("malloc");
        return 1;
    }

    for (int i = 0; i < n; i++)
        array[i] = i + 1;

    pthread_t tid[5];
    container args[5];

    pthread_mutex_init(&lock, NULL);

    int chunk = n / 5;

    for (int i = 0; i < 5; i++) {
        args[i].start = i * chunk;
        args[i].end   = (i == 4) ? n : (i + 1) * chunk;
        args[i].array = array;

        pthread_create(&tid[i], NULL, sum_and_max, &args[i]);
    }

    for (int i = 0; i < 5; i++)
        pthread_join(tid[i], NULL);

    printf("Sum = %d\n", global_sum);
    printf("Max = %d\n", global_max);

    pthread_mutex_destroy(&lock);
    free(array);

    return 0;
}
