#include <stdio.h>
#include <string.h>

int main(void) {
    char s[] = "abc\0def";
    printf("%zu %zu\n", strlen(s), sizeof(s));
    return 0;
}

