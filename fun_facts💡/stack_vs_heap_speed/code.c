#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    clock_t start, end;

    start = clock();
    for (int i = 0; i < 1000000; i++) {
        int x = i;
    }
    end = clock();
    printf("Stack time: %ld\n", end - start);

    start = clock();
    for (int i = 0; i < 1000000; i++) {
        int *p = malloc(sizeof(int));
        free(p);
    }
    end = clock();
    printf("Heap time: %ld\n", end - start);

    return 0;
}
