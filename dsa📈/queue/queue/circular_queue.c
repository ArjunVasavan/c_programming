#include <stdint.h>
#include <stdbool.h>

#define QUEUE_SIZE 8   // must be power of 2 for bitmask trick

typedef struct {
    uint8_t  buf[QUEUE_SIZE];
    uint8_t  head;    // next read  position
    uint8_t  tail;    // next write position
    uint8_t  count;
} RingBuffer;

void     rb_init    (RingBuffer *rb) { rb->head = rb->tail = rb->count = 0; }
bool     rb_empty   (RingBuffer *rb) { return rb->count == 0; }
bool     rb_full    (RingBuffer *rb) { return rb->count == QUEUE_SIZE; }

bool rb_enqueue(RingBuffer *rb, uint8_t data) {
    if (rb_full(rb)) return false;          // drop or return error
    rb->buf[rb->tail] = data;
    rb->tail = (rb->tail + 1) % QUEUE_SIZE; // or: & (QUEUE_SIZE-1)
    rb->count++;
    return true;
}

bool rb_dequeue(RingBuffer *rb, uint8_t *out) {
    if (rb_empty(rb)) return false;
    *out = rb->buf[rb->head];
    rb->head = (rb->head + 1) % QUEUE_SIZE;
    rb->count--;
    return true;
}

uint8_t rb_peek(RingBuffer *rb) {
    return rb->buf[rb->head];               // look without removing
}
