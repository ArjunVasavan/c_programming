#include <stdio.h>
#include <string.h>

int main(void) {
    char s[10] = "hello";
    strcpy(s + 3, "world");
    printf("%s\n", s);
    return 0;
}

