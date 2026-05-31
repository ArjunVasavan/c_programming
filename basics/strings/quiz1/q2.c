#include <stdio.h>

int main(void) {
    char *p = "12345";
    char c = *p++;
    printf("%c %c\n", c, *p);
    return 0;
}

