#include <cmath>
#include <cstddef>
#include <stdlib.h>
#include <stdio.h>

typedef struct Node{
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* top;
} Stack;

void push(Stack* s, int val ) {
    Node* new_node = malloc(sizeof(Node));
    new_node->data = val;
    new_node->next = s->top;
    s->top = new_node;
}

int pop(Stack* s) {
    if ( s->top == NULL ) return  -1;
    Node* temp = s->top;
    int val = s->top->data;
    s->top = s->top->next;
    free(s->top);
    return val;
}



int main(int argc, char** argv) {
    
}
