#include <stdio.h>

int main(void) {
    char s[] = "abc";
    char *p = s;
    p += 2;
    printf("%s\n", p - 1);
    return 0;
}

