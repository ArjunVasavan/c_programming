#include <stdio.h>
#define SIZE 5

typedef struct {
    int data; /* this will store the eke */
    int priority;
} Item;

Item queue[SIZE];
int count = 0;

void enqueue(int val, int pri) {
    if (count == SIZE) {
        printf("Queue Full\n");
        return;
    }
    queue[count].data = val;
    queue[count].priority = pri;
    count++;
    printf("Enqueued: %d (priority %d)\n", val, pri);
}

int dequeue() {
    if (count == 0) {
        printf("Queue Empty\n");
        return -1;
    }
    int highIdx = 0;
    for (int i = 1; i < count; i++) {
        if (queue[i].priority > queue[highIdx].priority)
            highIdx = i;
    }
    int val = queue[highIdx].data;
    for (int i = highIdx; i < count - 1; i++)
        queue[i] = queue[i + 1];
    count--;
    return val;
}

int main() {
    enqueue(100, 1);
    enqueue(200, 3);
    enqueue(300, 2);
    printf("Dequeued: %d\n", dequeue());  // 200 (priority 3)
    printf("Dequeued: %d\n", dequeue());  // 300 (priority 2)
    printf("Dequeued: %d\n", dequeue());  // 100 (priority 1)
    return 0;
}
