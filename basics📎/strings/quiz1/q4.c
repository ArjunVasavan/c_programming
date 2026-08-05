/* In C, adjacent string literals like "Hello" " " "World" are concatenated at compile time into "Hello World". s + 6 moves the pointer to the 7th character ('W'), so printf("%s\n", s + 6); prints "World". */

#include <stdio.h>

int main(void) {
    char s[] = "Hello" " " "World";
    printf("%s\n", s + 6);
    return 0;
}

