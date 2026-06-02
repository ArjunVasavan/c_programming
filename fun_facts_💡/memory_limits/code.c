#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Page size: %ld\n", sysconf(_SC_PAGESIZE));
    return 0;
}
