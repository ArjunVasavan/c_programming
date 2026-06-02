#include <stdio.h>
#include <stdlib.h>

int main() {
    int *a = malloc(4);
    int *b = malloc(4);

    printf("a: %p\n", a);
    printf("b: %p\n", b);

    if (b > a)
        printf("Heap grows upward\n");
    else
        printf("Heap grows downward\n");

    return 0;
}
