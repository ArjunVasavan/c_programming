#include <stdio.h>

int main(void) {
    char s[] = "012345";
    char *p = s + 1;
    *(p += 2) = 'X';
    printf("%s\n", s);
    return 0;
}

