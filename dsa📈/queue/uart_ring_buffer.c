#include <stdio.h>
#define BUFFER_SIZE 8

typedef struct {
    char buffer[BUFFER_SIZE];
    int head;  // dequeue from here
    int tail;  // enqueue here
    int count;
} RingBuffer;

void rb_init(RingBuffer* rb) {
    rb->head = rb->tail = rb->count = 0;
}

int rb_isFull(RingBuffer* rb) {
    return rb->count == BUFFER_SIZE;
}

int rb_isEmpty(RingBuffer* rb) {
    return rb->count == 0;
}

void rb_enqueue(RingBuffer* rb, char c) {
    if (rb_isFull(rb)) {
        printf("Buffer Full! Dropping: %c\n", c);
        return;
    }
    rb->buffer[rb->tail] = c;
    rb->tail = (rb->tail + 1) % BUFFER_SIZE;
    rb->count++;
}

char rb_dequeue(RingBuffer* rb) {
    if (rb_isEmpty(rb)) {
        printf("Buffer Empty\n");
        return '\0';
    }
    char c = rb->buffer[rb->head];
    rb->head = (rb->head + 1) % BUFFER_SIZE;
    rb->count--;
    return c;
}

int main() {
    RingBuffer uart_rx;
    rb_init(&uart_rx);

    // Simulating ISR receiving bytes
    rb_enqueue(&uart_rx, 'H');
    rb_enqueue(&uart_rx, 'E');
    rb_enqueue(&uart_rx, 'L');
    rb_enqueue(&uart_rx, 'L');
    rb_enqueue(&uart_rx, 'O');

    // Main loop processing bytes
    printf("Received: ");
    while (!rb_isEmpty(&uart_rx)) {
        printf("%c", rb_dequeue(&uart_rx));
    }
    printf("\n");
    return 0;
}
