#include <stdio.h>

int main() {
    unsigned int x = 1;
    char *c = (char*)&x;

    if (*c)
        printf("Little Endian\n");
    else
        printf("Big Endian\n");

    return 0;
}
