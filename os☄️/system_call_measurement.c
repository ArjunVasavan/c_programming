#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>

#define ITERS 1000000

/* NOTE: even on failing, the system call still goes inside the kernel.
 * Here we pass an invalid fd (-1) to read(), so it fails fast (EBADF),
 * but the kernel is still entered -- so this measures raw syscall overhead,
 * not actual I/O work. Effectively a 0-byte no-op syscall.
 *
 * Timing uses struct timeval (from <sys/time.h>) via gettimeofday():
 *   struct timeval {
 *       time_t      tv_sec;   
 *       suseconds_t tv_usec;  
 *   };
 *   tv_sec  = whole seconds
 *   tv_usec = microseconds remainder (0 - 999999)
 *
 * 1e6 = 1,000,000 as a double, used to convert the tv_sec difference
 * into microseconds so it can be added to the tv_usec difference,
 * giving total elapsed time in microseconds. Dividing by ITERS at
 * the end gives the average per-syscall cost in microseconds.
 */
int main() {
    struct timeval start, end;
    gettimeofday(&start, NULL);

    for (int i = 0; i < ITERS; i++) {
        read(-1, NULL, 0);   /* invalid fd -> fails fast, still enters kernel */
    }

    gettimeofday(&end, NULL);

    /* NOTE: converting two timestamps into elapsed microseconds:
     *
     * (end.tv_sec - start.tv_sec)
     *   -> difference in whole seconds between end and start.
     *
     * ... * 1e6
     *   -> converts that seconds difference into microseconds,
     *      since 1 second = 1,000,000 microseconds.
     *
     * + (end.tv_usec - start.tv_usec)
     *   -> adds the leftover microsecond difference (the sub-second part)
     *      on top of the converted seconds.
     *
     * Together: usec = total elapsed time, expressed fully in microseconds,
     * by combining the seconds part (scaled up) and the microseconds part.
     *
     * Example: start = 10.500000s, end = 10.500250s
     *   tv_sec diff  = 0        -> 0 * 1e6 = 0
     *   tv_usec diff = 250      -> +250
     *   usec = 250  (i.e. 250 microseconds elapsed)
     */
    double usec = (end.tv_sec - start.tv_sec) * 1e6 /* here second is converted to microseconds */
                + (end.tv_usec - start.tv_usec); /* here adding leftover microseconds */

    /* Divide total elapsed microseconds by number of iterations
     * to get the AVERAGE cost of a single syscall in microseconds. */
    printf("syscall cost: %f us\n", usec / ITERS);
    return 0;
}
