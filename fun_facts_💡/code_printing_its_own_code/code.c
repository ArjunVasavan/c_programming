#include <stdio.h>

int main() {
    FILE *f = fopen(__FILE__, "r");
    char ch;

    while ((ch = fgetc(f)) != EOF)
        putchar(ch);

    fclose(f);
    return 0;
}
