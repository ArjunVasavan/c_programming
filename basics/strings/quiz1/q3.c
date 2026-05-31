/* Why this happens */
/* strlen() */

/* Walks through the string until it finds '\0'. */

/* Returns the count of characters before it. */

/* The null terminator is a stop signal, not part of the count. */

/* sizeof */

/* Evaluated at compile time for arrays. */

/* Returns the total number of bytes the array occupies in memory. */

/* For char s[] = "Hello"; → 6 bytes ('H' 'e' 'l' 'l' 'o' '\0'). */
#include <stdio.h>
#include <string.h>

int main(void) {
    char s[] = "Hello";
    printf("%zu %zu\n", strlen(s), sizeof(s));
    return 0;
}

