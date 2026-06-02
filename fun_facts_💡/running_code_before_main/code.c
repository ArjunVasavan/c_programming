#include <stdio.h>

void __attribute__((constructor)) start() {
    printf("Before main!\n");
}

int main() {
    printf("Inside main\n");
    return 0;
}
