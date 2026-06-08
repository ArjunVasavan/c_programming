#include <stdio.h>
/* NOTE: Queue
 * queue is FIFO data structure
 * the element inserted first is the element removed first
 * Enqueue -> add to the rear
 * Dequque -> remove from front
 */

/* O(1) enqueue and dequeue */
/* O(n) space fixed */

#define MAX 5

typedef struct {
    int data[MAX];
    int front, rear, size;
} queue;

void init_queue(queue* q) {
    q->front = q->front = q->size = 0;
}

int is_full(queue* q) {
    return q->size == MAX;
}

int is_empty(queue* q) {
    return q->size == 0;
}

void enqueue(queue* q, int val) {
    if (is_full(q)) {
        printf("Queue if FULL!\n");
        return;
    }

    q->data[q->rear] = val;
    q->rear = (q->rear + 1) % MAX; /* for wrap around */
    q->size++;
}

int dequeue(queue* q) {
    if ( is_empty(q)) {
        printf("Queue is Empty\n");
        return -1;
    }

    int val = q->data[q->front];
    q->front =  ( q->front + 1 ) % MAX ; /* wrapping around front also */
    return val;
}

int main(int argc, char** argv) {



}
