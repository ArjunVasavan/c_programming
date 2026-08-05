/* NOTE: What are brk and sbrk?

   Both are legacy Unix system calls that manage the "program break" -
   the address marking the end of a process's heap segment. Growing the
   heap (to get more memory) or shrinking it means moving this break
   address up or down.

   brk(void *addr) sets the program break to an absolute address.
   sbrk(intptr_t increment) moves the break by a relative amount and
   returns the PREVIOUS break address - so sbrk(0) is a common trick
   to just query the current break without changing it.

   These are what malloc() traditionally uses internally to request
   more heap memory from the OS (though modern malloc implementations
   often use mmap for large allocations instead). */

#include <stdio.h>
#include <unistd.h>

int main(void) {
    /* sbrk(0) returns the CURRENT program break without moving it */
    void *initial_break = sbrk(0);
    printf("Initial program break: %p\n", initial_break);

    /* Request 4096 extra bytes (e.g. one page) from the OS by moving
       the break forward. sbrk returns the OLD break on success. */
    void *old_break = sbrk(4096);
    if (old_break == (void *) -1) {
        perror("sbrk failed");
        return 1;
    }
    printf("Old break before growing: %p\n", old_break);

    void *new_break = sbrk(0);
    printf("New program break after growing: %p\n", new_break);
    printf("Heap grew by: %ld bytes\n",
           (char *) new_break - (char *) old_break);

    /* We can now safely use the newly allocated region between
       old_break and new_break as raw memory */
    char *heap_mem = (char *) old_break;
    heap_mem[0] = 'H';
    heap_mem[1] = 'i';
    heap_mem[2] = '\0';
    printf("Data written to newly grabbed heap memory: %s\n", heap_mem);

    /* Shrink the break back down, releasing the memory back to the OS */
    if (brk(initial_break) != 0) {
        perror("brk failed to shrink");
        return 1;
    }
    printf("Program break after shrinking back: %p\n", sbrk(0));

    return 0;
}
