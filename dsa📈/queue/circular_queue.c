 /* can be used on ADC ring buffer or UART ring buffer o */

#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

int isFull() {
    return (front == (rear + 1) % SIZE); /* here we are rounding and checking is anything left before front */
}

int isEmpty() {
    return (front == -1); /* this means its an -1 flag telling we havent even added anything */
}

void enqueue(int val) {
    if (isFull()) { /* before adding checking if queue is full or not */
        printf("Queue Full\n");
        return;
    }
    if (isEmpty()) front = 0; /* if empty we are making front as 0 */
    rear = (rear + 1) % SIZE; /* this will round out and find the left spot we can add */
    queue[rear] = val; /* adding value to it */
    printf("Enqueued: %d\n", val);
}

int dequeue() {
    if (isEmpty()) { /* we cannot dequeue if queue is empty */
        printf("Queue Empty\n");
        return -1;
    }
    int val = queue[front]; /* taking out the value from front */
    if (front == rear) { /* this is to check if last element is also removed */
        front = rear = -1;  // last element removed
    } else {
        front = (front + 1) % SIZE; /* else we are adding element */
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
