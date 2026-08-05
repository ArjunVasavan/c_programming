/* s points to "abcdef". */

/* s + 2 points to "cdef". */

/* "%.3s" tells printf to print only the first 3 characters from "cdef". */

/* Those 3 characters are: c, d, e. */

#include <stdio.h>

int main(void) {
    char *s = "abcdef";
    printf("%.3s\n", s + 2);
    return 0;
}

