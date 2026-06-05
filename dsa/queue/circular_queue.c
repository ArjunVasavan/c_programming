#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

int isFull() {
    return (front == (rear + 1) % SIZE);
}

int isEmpty() {
    return (front == -1);
}

void enqueue(int val) {
    if (isFull()) {
        printf("Queue Full\n");
        return;
    }
    if (isEmpty()) front = 0;
    rear = (rear + 1) % SIZE;
    queue[rear] = val;
    printf("Enqueued: %d\n", val);
}

int dequeue() {
    if (isEmpty()) {
        printf("Queue Empty\n");
        return -1;
    }
    int val = queue[front];
    if (front == rear) {
        front = rear = -1;  // last element removed
    } else {
        front = (front + 1) % SIZE;
    }
    return val;
}

void display() {
    if (isEmpty()) {
        printf("Queue Empty\n");
        return;
    }
    printf("Queue: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    display();
    printf("Dequeued: %d\n", dequeue());
    printf("Dequeued: %d\n", dequeue());
    enqueue(50);
    enqueue(60);  // reuses freed space
    display();
    return 0;
}
