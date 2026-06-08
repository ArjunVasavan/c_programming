#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *head, *tail;
} Queue;

void init(Queue *q) { q->head = q->tail = NULL; }

void enqueue(Queue *q, int val) {
    Node *n = malloc(sizeof(Node));
    n->data = val; n->next = NULL;
    if (!q->tail) { q->head = q->tail = n; return; }
    q->tail->next = n;
    q->tail = n;
}

int dequeue(Queue *q) {
    if (!q->head) { printf("Empty\n"); return -1; }
    Node *tmp = q->head;
    int val = tmp->data;
    q->head = q->head->next;
    if (!q->head) q->tail = NULL; // queue became empty
    free(tmp);
    return val;
}
