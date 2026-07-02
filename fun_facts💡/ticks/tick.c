#include <stdio.h>
#include <unistd.h>   /* required for sysconf() */

/*
 * TICK:
 * A tick is one occurrence of the periodic hardware timer interrupt.
 * The kernel configures a timer to fire at a fixed rate (HZ times per
 * second). Each firing of that interrupt is called a "tick".
 * HZ itself is a kernel compile-time constant (e.g. 100, 250, 1000)
 * and is NOT directly visible to user-space programs.
 *
 * JIFFY:
 * A jiffy is the time DURATION of one tick interval, i.e. 1/HZ seconds.
 * The kernel keeps a running counter called "jiffies", which increments
 * by exactly 1 on every tick. So jiffies = total ticks since boot.
 *
 * Since user-space code cannot read HZ directly, POSIX provides
 * sysconf(_SC_CLK_TCK) to query the effective clock tick rate at
 * runtime. This is exactly what's needed to convert tick-based values
 * (like utime/stime fields from /proc/[pid]/stat) into real seconds.
 */

int main(void)
{
    /* Ask the OS at runtime how many clock ticks occur per second.
     * This replaces the kernel's internal HZ value, which user-space
     * cannot access directly. On most Linux systems this returns 100. */
    long clk_tck = sysconf(_SC_CLK_TCK);

    if (clk_tck == -1) {
        perror("sysconf failed");
        return 1;
    }

    printf("Clock ticks per second (HZ, queried via sysconf): %ld\n", clk_tck);

    /* Example: utime + stime value read from /proc/[pid]/stat,
     * reported by the kernel in clock ticks, not seconds. */
    unsigned long ticks = 5500;

    /* Convert ticks -> seconds using the formula:
     *     seconds = ticks / HZ
     * Here HZ is replaced by the runtime value from sysconf(),
     * so the conversion stays correct even if HZ differs across systems. */
    double seconds = (double)ticks / clk_tck;

    printf("Ticks: %lu\n", ticks);
    printf("Elapsed time: %.3f seconds\n", seconds);

    return 0;
}
