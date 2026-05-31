#include <stdio.h>

int main(void) {
    char s[] = "a\0b";
    printf("%s\n", s);
    printf("%c\n", s[2]);
    return 0;
}

