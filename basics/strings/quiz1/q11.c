#include <stdio.h>
#include <string.h>

int main(void) {
    char s1[] = "foo";
    char s2[] = "bar";
    strncat(s1, s2, 2);
    printf("%s\n", s1);
    return 0;
}

