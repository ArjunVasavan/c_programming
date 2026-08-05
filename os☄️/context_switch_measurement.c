/* _GNU_SOURCE is a "feature test macro". By default, glibc (Linux's C
 * library) only exposes the standard POSIX functions/macros -- it hides
 * extra Linux/GNU-specific stuff unless you explicitly ask for it.
 *
 * Things like sched_setaffinity(), CPU_SET(), CPU_ZERO(), and cpu_set_t
 * are NOT part of standard POSIX -- they're Linux/GNU-specific extensions.
 * So without this line, the compiler wouldn't even know these functions
 * exist, and you'd get errors like "implicit declaration of function".
 *
 * Defining _GNU_SOURCE before any #include tells glibc:
 * "unlock all the extra GNU/Linux-only functions and macros too."
 * This MUST be defined before any #include, otherwise it has no effect.
 */
#define _GNU_SOURCE

#include <sched.h>
#include <stdio.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <unistd.h>

#define ITERS 100000

/* This function forces the calling process to run only on CPU core 0.
 *
 * Why do we care? On a multi-core machine, the OS scheduler can freely
 * move parent and child processes to different cores. If parent is on
 * core 0 and child is on core 1, then when they "switch" between each
 * other, it's not really a classic context switch anymore -- both are
 * running truly in parallel on separate cores, so we wouldn't be
 * measuring the real cost of one core switching between two tasks.
 *
 * By pinning BOTH parent and child to the SAME core (core 0), we force
 * the OS to actually stop one and start the other on that one core --
 * which is the real context switch we want to measure.
 */
void pin_to_cpu0() {
    /* cpu_set_t is just a structure that represents "a set of CPU cores".
     * Think of it like a checklist with one box per core (box 0, box 1, ...).
     * We're going to tick the box for core 0 and leave everything else unticked.
     */
    cpu_set_t set;

    /* Clear the checklist -- start with all boxes unticked (no cores selected). */
    CPU_ZERO(&set);

    /* Tick the box for core 0 -- this means "only allow running on core 0". */
    CPU_SET(0, &set);

    /* Apply this checklist to the CURRENT process.
     * The first argument "0" means "apply to myself" (the calling process),
     * not some other process by PID.
     * This tells the OS scheduler: "only ever run me on core 0."
     */
    sched_setaffinity(0, sizeof(set), &set);
}

int main() {
    int p1[2], p2[2];   /* p1: parent->child, p2: child->parent */
    pipe(p1);
    pipe(p2);
    char buf;

    pid_t pid = fork();

    /* Both parent and child independently call this after fork(),
     * so both end up locked to core 0 -- forcing them to take turns
     * on the same core instead of running on separate cores at once. */
    pin_to_cpu0();

    if (pid == 0) {
        /* child: read one byte from parent, immediately send one byte back.
         * This "ping" from parent forces the OS to switch away from parent
         * and run the child instead (since child is waiting on read()). */
        for (int i = 0; i < ITERS; i++) {
            read(p1[0], &buf, 1);
            write(p2[1], &buf, 1);
        }
        return 0;
    }

    /* parent: send one byte to child, then wait to read the reply.
     * While parent is blocked on read(), the OS switches to child --
     * then when child replies, OS switches back to parent. That's
     * 2 switches per loop iteration (parent->child, child->parent). */
    struct timeval start, end;
    gettimeofday(&start, NULL);

    for (int i = 0; i < ITERS; i++) {
        write(p1[1], &buf, 1);
        read(p2[0], &buf, 1);
    }

    gettimeofday(&end, NULL);
    waitpid(pid, NULL, 0);

    /* Same math as before: combine seconds + microseconds difference
     * into one total microsecond count. */
    double usec = (end.tv_sec - start.tv_sec) * 1e6
                + (end.tv_usec - start.tv_usec);

    /* each loop iteration forces 2 switches: parent->child, child->parent */
    printf("context switch cost: %f us\n", usec / (2 * ITERS));
}
