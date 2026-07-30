#include <stdio.h>

void __attribute__((destructor)) end() {
    printf("After main!\n");
}

int main() {
    printf("Inside main\n");
    return 0;
}
