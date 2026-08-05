#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sched.h>

#define STACK_SIZE (1024 * 1024)  /* 1 MB stack for the child */

int shared_var = 100;  /* will be shared if CLONE_VM is used */

int child_function(void* arg) {
    printf("Child: shared_var before change = %d\n", shared_var);
    shared_var = 999;  /* modify it */
    printf("Child: shared_var after change = %d\n", shared_var);
    return 0;
}

int main() {
    /* Allocate stack for the child (clone requires an explicit stack) */
    char* stack = malloc(STACK_SIZE);
    char* stack_top = stack + STACK_SIZE;  /* stack grows downward */

    printf("Parent: shared_var before clone = %d\n", shared_var);

    pid_t pid = clone(
        child_function,        /* function child will execute */
        stack_top,              /* top of the allocated stack */
        CLONE_VM | SIGCHLD,     /* flags: share memory (like a thread) + send SIGCHLD on exit */
        NULL                    /* argument passed to child_function */
    );

    if (pid == -1) {
        perror("clone failed");
        exit(1);
    }

    waitpid(pid, NULL, 0);  /* wait for child to finish */

    printf("Parent: shared_var after child exits = %d\n", shared_var);

    free(stack);
    return 0;
}
