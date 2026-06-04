#include <stdio.h>
#include <stdint.h>
// Priority task queue — common in RTOS internals
typedef struct {
    uint8_t task_id;
    uint8_t priority;
} QueueItem_t;

typedef struct {
    QueueItem_t items[4];
    uint8_t     count;
} TaskQueue_t;

void enqueue(TaskQueue_t *q, QueueItem_t item) {
    if (q->count < 4) q->items[q->count++] = item;
}

int main() {
    TaskQueue_t q = {0};
    enqueue(&q, (QueueItem_t){1, 3});
    enqueue(&q, (QueueItem_t){2, 1});
    enqueue(&q, (QueueItem_t){3, 2});
    for (int i = 0; i < q.count; i++)
        printf("Task=%d Pri=%d\n", q.items[i].task_id, q.items[i].priority);
}
// Output:
// Task=1 Pri=3
// Task=2 Pri=1
// Task=3 Pri=2
