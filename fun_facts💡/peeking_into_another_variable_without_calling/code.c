#include <stdio.h>

int main() {
    int a = 10, b = 20;

    int *p = &a;

    printf("%d\n", *(p + 1));  // accessing b blindly

    return 0;
}
