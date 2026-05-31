#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

bool where_stack_grows(int *prev) {
    int x = 0;
    if (prev == NULL) {
        return where_stack_grows(&x);
    } else {
        return (uintptr_t)&x > (uintptr_t)prev;
    }
}

int main(void) {
    printf("The Stack Grows %s\n", where_stack_grows(NULL) ? "Upward" : "Downward");
}
