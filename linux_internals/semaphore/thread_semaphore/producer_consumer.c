/*
=============================================
PRODUCER–CONSUMER LOGIC (BOUNDED BUFFER)
=============================================

Goal:
- Producer generates items and stores them in a fixed-size buffer
- Consumer removes items from the same buffer
- Both run concurrently without data corruption

Problems handled:
1. Producer must NOT write when buffer is full
2. Consumer must NOT read when buffer is empty
3. Only ONE thread must access buffer at a time

Semaphores used:

1) buffer_mutex (binary semaphore)
   - Ensures mutual exclusion
   - Only one thread can access buffer at any moment

2) empty_slots (counting semaphore)
   - Tracks number of empty slots in buffer
   - Producer waits if empty_slots == 0

3) full_slots (counting semaphore)
   - Tracks number of filled slots
   - Consumer waits if full_slots == 0

Producer steps:
1. Wait for empty slot
2. Lock buffer
3. Insert item
4. Unlock buffer
5. Signal full slot

Consumer steps:
1. Wait for full slot
2. Lock buffer
3. Remove item
4. Unlock buffer
5. Signal empty slot

This prevents:
- Buffer overflow
- Buffer underflow
- Race conditions
=============================================
*/


#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_BUFFER_SIZE 10

/* Shared buffer and indices */
int buffer[MAX_BUFFER_SIZE];
int front_index = 0;
int rear_index  = 0;

/* Semaphores */
sem_t buffer_mutex;     // Protects shared buffer
sem_t full_slots;       // Number of filled slots
sem_t empty_slots;      // Number of empty slots

/* ================= PRODUCER THREAD ================= */
void* producer_thread(void* arg)
{
    int item_id;

    for (item_id = 0; ; item_id++)
    {
        sem_wait(&empty_slots);     // Wait for empty space
        sem_wait(&buffer_mutex);    // Lock buffer

        printf("PRODUCED: %d\n", item_id);

        buffer[rear_index % MAX_BUFFER_SIZE] = item_id;
        rear_index++;

        sleep(1);

        sem_post(&buffer_mutex);    // Unlock buffer
        sem_post(&full_slots);      // Signal new item
    }

    return NULL;
}

/* ================= CONSUMER THREAD ================= */
void* consumer_thread(void* arg)
{
    int consumed_item;

    for (;;)
    {
        sem_wait(&full_slots);      // Wait for available item
        sem_wait(&buffer_mutex);    // Lock buffer

        consumed_item = buffer[front_index % MAX_BUFFER_SIZE];
        front_index++;

        printf("CONSUMED: %d\n", consumed_item);

        sleep(1);

        sem_post(&buffer_mutex);    // Unlock buffer
        sem_post(&empty_slots);     // Signal free space
    }

    return NULL;
}

/* ================= MAIN ================= */
int main(void)
{
    pthread_t producer_tid, consumer_tid;

    sem_init(&buffer_mutex, 0, 1);
    sem_init(&full_slots, 0, 0);
    sem_init(&empty_slots, 0, MAX_BUFFER_SIZE);

    pthread_create(&producer_tid, NULL, producer_thread, NULL);
    pthread_create(&consumer_tid, NULL, consumer_thread, NULL);

    pthread_join(producer_tid, NULL);
    pthread_join(consumer_tid, NULL);

    return 0;
}

