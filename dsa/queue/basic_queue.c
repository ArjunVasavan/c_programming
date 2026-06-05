#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1; /* first we have to initialize with -1 */

void enqueue(int val) {
    if (rear == SIZE - 1) { /* if rear reached the end */
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) front = 0; /* this is to ensure we have started adding element  */
    queue[++rear] = val; /* adding element */
    printf("Enqueued: %d\n", val);
}

int dequeue() {
    if (front == -1 || front > rear) { /* this means we havent added any elements */
        printf("Queue Underflow\n");
        return -1;
    }
    return queue[front++]; /* returning element and incrementing front */
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue Empty\n");
        return;
    }
    printf("Queue: ");
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    printf("Dequeued: %d\n", dequeue());
    display();
    return 0;
}
