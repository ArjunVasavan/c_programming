#include <stdio.h>
#include <stdint.h>

// Struct pointing to itself — used in queues, schedulers
typedef struct Node {
    int         data;
    struct Node *next;
} Node_t;

int main() {
    Node_t a = {10, NULL};
    Node_t b = {20, NULL};
    a.next = &b;
    printf("%d -> %d\n", a.data, a.next->data);
}
// Output: 10 -> 20
