/* NOTE: What is mmap and how does it differ from brk/sbrk?

   mmap() asks the OS to map a region of memory directly into the
   process's address space - it can be backed by a file, or, when
   used with MAP_ANONYMOUS, backed by nothing (just zero-initialized
   RAM). Unlike sbrk, which can only grow/shrink a single contiguous
   heap from one end, mmap can create independent memory regions
   anywhere in the address space, and each region can be unmapped
   individually with munmap - which is why modern malloc implementations
   use mmap for large allocations instead of extending the heap. */

#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>
#include <string.h>

int main(void) {
    size_t length = 4096;  /* one page, typically 4KB */

    /* Request an anonymous memory mapping directly from the OS:
       - addr = NULL      : let the kernel choose the address
       - length           : size of the mapping in bytes
       - PROT_READ|WRITE  : we want to read and write this memory
       - MAP_PRIVATE      : changes are private to this process
       - MAP_ANONYMOUS    : not backed by a file, just raw memory
       - fd = -1, offset 0: required/ignored when using MAP_ANONYMOUS */
    void *region = mmap(NULL, length,
                        PROT_READ | PROT_WRITE,
                        MAP_PRIVATE | MAP_ANONYMOUS,
                        -1, 0);

    if (region == MAP_FAILED) {
        perror("mmap failed");
        return 1;
    }

    printf("mmap returned region at address: %p\n", region);

    /* Use the mapped memory just like any other buffer */
    char *buf = (char *) region;
    strcpy(buf, "Hello from mmap'd memory!");
    printf("Data written to mapped memory: %s\n", buf);

    /* mmap'd anonymous memory is zero-initialized by the kernel */
    printf("Byte at offset 100 (should be 0): %d\n", buf[100]);

    /* Release the mapping back to the OS when done */
    if (munmap(region, length) != 0) {
        perror("munmap failed");
        return 1;
    }
    printf("Memory unmapped successfully.\n");

    return 0;
}
