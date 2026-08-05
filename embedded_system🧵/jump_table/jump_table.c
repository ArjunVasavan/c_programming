/* NOTE: A jump table is an array of function pointers, where each array
   index corresponds to a specific function to call - instead of using
   a long if/else or switch chain to decide what to run, you simply
   look up the function by index and call it directly.

   How would you build a jump table using an array of function pointers,
   and where does driver code use this pattern?

   To build one: define a function pointer type, write a set of functions
   that all match that signature, then store them in an array where the
   index represents an opcode/command/event ID. Calling table[i](...)
   jumps straight to the correct function.

   Driver code uses this pattern heavily because a driver's job is to
   expose a uniform interface over very different hardware. Examples:
   the Linux file_operations struct (open/read/write/ioctl function
   pointers per device), interrupt vector tables (indexed by interrupt
   number), and syscall tables (indexed by syscall number) all use this
   exact array-of-function-pointers dispatch mechanism. */

#include <stdio.h>

/* Define a function pointer type: takes two ints, returns an int */
typedef int (*op_func)(int, int);

/* Functions matching that signature */
int op_add(int a, int b) { return a + b; }
int op_sub(int a, int b) { return a - b; }
int op_mul(int a, int b) { return a * b; }
int op_div(int a, int b) { return b != 0 ? a / b : 0; }

/* The jump table: index 0 = add, 1 = sub, 2 = mul, 3 = div */
op_func jump_table[] = { op_add, op_sub, op_mul, op_div };

int main(void) {
    int a = 10, b = 5;

    for (int opcode = 0; opcode < 4; opcode++) {
        int result = jump_table[opcode](a, b);
        printf("opcode %d: result = %d\n", opcode, result);
    }

    return 0;
}
