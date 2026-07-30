/* NOTE: This program demonstrates that a pointer's size depends only on
   the machine's architecture (32-bit vs 64-bit), not on the type of data
   it points to. We declare pointers to different types - char, int,
   double, and a large struct - and print their sizes using sizeof().
   All pointer types will show the same size (4 bytes on 32-bit, 8 bytes
   on 64-bit), even though the sizes of the underlying data types differ
   drastically. This confirms that a pointer simply stores a memory
   address, and the width needed to represent that address is fixed by
   the architecture - not by what is stored at that address. */

#include <stdio.h>

int main(void) {
    char c;
    int i;
    double d;
    struct Big { int arr[100]; } big;  /* a much larger struct */

    char   *pc = &c;
    int    *pi = &i;
    double *pd = &d;
    struct Big *pbig = &big;
    void   *pv = NULL;

    /* Print the size of each pointer variable itself */
    printf("Size of char*        : %zu bytes\n", sizeof(pc));
    printf("Size of int*         : %zu bytes\n", sizeof(pi));
    printf("Size of double*      : %zu bytes\n", sizeof(pd));
    printf("Size of struct Big*  : %zu bytes\n", sizeof(pbig));
    printf("Size of void*        : %zu bytes\n", sizeof(pv));

    /* Now print the size of the actual data each pointer points to,
       to show that the data sizes vary even though pointer sizes don't */
    printf("\nSize of the actual data they point to:\n");
    printf("sizeof(char)   = %zu\n", sizeof(c));
    printf("sizeof(int)    = %zu\n", sizeof(i));
    printf("sizeof(double) = %zu\n", sizeof(d));
    printf("sizeof(struct Big) = %zu\n", sizeof(big));

    return 0;
}
