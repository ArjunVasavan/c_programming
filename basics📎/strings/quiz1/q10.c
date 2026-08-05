#include <stdio.h>

int main(void) {
    char s[] = "abcd";
    char *p = s + 4;
    printf("%d\n", (int)(p - s));
    return 0;
}

