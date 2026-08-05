/* NOTE: What is pointer aliasing? What does the restrict qualifier
   promise the compiler?

   Pointer aliasing is when two pointers refer to the same memory
   location, so a write through one pointer affects what the other
   pointer reads. The compiler must assume this could happen unless
   told otherwise, which blocks certain optimizations (like keeping
   values in registers instead of reloading from memory).

   restrict is a promise from the programmer that, for this pointer's
   lifetime, no other pointer will access the same memory. This lets
   the compiler skip the "safe but slow" aliasing checks and optimize
   more aggressively. Violating this promise is undefined behavior -
   the compiler is not required to check it. */

#include <stdio.h>

/* Without restrict: compiler must assume a and b might overlap,
   so it reloads *a after every write to *b, just in case */
void add_no_restrict(int *a, int *b, int *result, int n) {
    for (int i = 0; i < n; i++) {
        result[i] = a[i] + b[i];
    }
}

/* With restrict: compiler is told a, b, and result never overlap,
   so it can cache values in registers and vectorize the loop freely */
void add_restrict(int *restrict a, int *restrict b,
                   int *restrict result, int n) {
    for (int i = 0; i < n; i++) {
        result[i] = a[i] + b[i];
    }
}

int main(void) {
    int a[5]      = {1, 2, 3, 4, 5};
    int b[5]      = {10, 20, 30, 40, 50};
    int result[5] = {0};

    add_restrict(a, b, result, 5);

    printf("Result: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}
