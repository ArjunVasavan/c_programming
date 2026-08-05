/* NOTE: Why does sizeof(arr) give a different result inside a function
   than in the caller?

   Because arrays decay into pointers when passed as function arguments.
   The caller's array variable knows its full size, but the function
   parameter is really just a pointer to the first element - it has
   lost all information about how many elements the array has. So
   sizeof(arr) inside the function measures the pointer's size, not
   the array's size.

   Why was C designed this way?
   C was designed in the early 1970s for efficiency and simplicity,
   running on hardware with very limited memory and no built-in support
   for rich type metadata. Passing a whole array by value would mean
   copying every element onto the stack on each call - expensive for
   large arrays, and wasteful since most array operations just need to
   walk through elements starting at some address. Passing a pointer to
   the first element instead is cheap (just one machine word), matches
   how arrays are stored in memory (a contiguous block accessed via
   base address + offset), and keeps the language close to the
   underlying hardware, which was central to C's design philosophy:
   give the programmer full control and minimal overhead, even if that
   means the programmer must manually track lengths themselves. */

#include <stdio.h>

void print_sizes(int arr[10]) {  /* really just int *arr underneath */
    printf("Inside function, sizeof(arr) = %zu bytes\n", sizeof(arr));
}

int main(void) {
    int arr[10];

    printf("Inside caller, sizeof(arr) = %zu bytes\n", sizeof(arr));

    print_sizes(arr);

    return 0;
}
