#include <semaphore.h>

sem_t sem;

int main() {
    sem_init(&sem, 0, 1);   // ready to use

    // ... create threads, use sem_wait/sem_post ...

    sem_destroy(&sem);
    return 0;
}
