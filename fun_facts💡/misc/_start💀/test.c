/*
========================================
 COMPILE:
 gcc -nostdlib -static -Wl,-e,_start test.c -o a.out
========================================
*/

typedef unsigned long size_t;

/* syscall: write */
long sys_write(int fd, const void *buf, size_t count) {
    long ret;
    __asm__ volatile (
        "mov $1, %%rax\n"
        "syscall"
        : "=a"(ret)
        : "D"(fd), "S"(buf), "d"(count)
        : "rcx", "r11", "memory"
    );
    return ret;
}

/* syscall: exit */
void sys_exit(int status) {
    __asm__ volatile (
        "mov $60, %%rax\n"
        "syscall"
        :
        : "D"(status)
        : "rcx", "r11", "memory"
    );
}

/*
----------------------------------------
 NAKED function = NO compiler prologue
----------------------------------------
*/
__attribute__((naked)) void _start() {
    __asm__ volatile (

        // rdi = stack pointer (original rsp)
        "mov %rsp, %rdi\n"

        // call C function with stack pointer
        "call real_start\n"
    );
}

void real_start(long *stack) {

    int argc = stack[0];
    char **argv = (char **)(stack + 1);

    sys_write(1, "Arguments:\n", 11);

    for (int i = 0; i < argc; i++) {
        char *arg = argv[i];

        for (int j = 0; arg[j] != '\0'; j++) {
            sys_write(1, &arg[j], 1);
        }

        sys_write(1, "\n", 1);
    }

    sys_exit(0);
}
