#include <stdio.h>

int global = 10;

void func() {}

int main() {
    int local = 20;

    printf("Code (func): %p\n", func);
    printf("Global: %p\n", &global);
    printf("Local: %p\n", &local);

    return 0;
}
