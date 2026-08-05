#include <stdint.h>
#include <stdio.h>
// Fixed-size circular queue — no malloc, safe for embedded
#define SIZE 4
typedef struct {
    int     buf[SIZE];
    uint8_t head, tail, count;
} RingBuf_t;

void push(RingBuf_t *rb, int val) {
    if (rb->count < SIZE) { 
        rb->buf[rb->head] = val;
        rb->head = (rb->head+1)%SIZE; 
        rb->count++;
    }
}
int pop(RingBuf_t *rb) {
    int v = rb->buf[rb->tail];
    rb->tail = (rb->tail+1)%SIZE; 
    rb->count--; 
    return v;
}

int main() {
    RingBuf_t rb = {0};
    push(&rb, 10); push(&rb, 20); push(&rb, 30);
    printf("%d %d %d\n", pop(&rb), pop(&rb), pop(&rb));
}
// Output: 10 20 30
