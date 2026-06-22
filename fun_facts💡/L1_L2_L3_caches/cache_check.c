/*
 * cache_check.c
 * 
 * This program checks your CPU's L1, L2, and L3 cache sizes
 * by reading memory of increasing sizes and measuring how long it takes.
 *
 * KEY IDEA:
 *   - If data fits in L1 cache  → access is VERY FAST  (~1-4 ns)
 *   - If data fits in L2 cache  → access is FAST       (~5-10 ns)
 *   - If data fits in L3 cache  → access is MEDIUM     (~20-40 ns)
 *   - If data exceeds all cache → access is SLOW        (~60-100 ns)
 *
 * HOW TO COMPILE:
 *   gcc -O0 -o cache_check cache_check.c
 *
 * HOW TO RUN:
 *   ./cache_check
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/* -----------------------------------------------
 * CONSTANTS
 * ----------------------------------------------- */
#define KB              1024
#define MB              (1024 * KB)
#define CACHE_LINE      64          /* Most CPUs use 64-byte cache lines */
#define REPEAT          5000000     /* Number of memory reads per test   */
#define MAX_BUFFER      (64 * MB)   /* Maximum memory to test: 64 MB     */


/* -----------------------------------------------
 * get_time_ns()
 * Returns current time in nanoseconds.
 * Used to measure how long memory access takes.
 * ----------------------------------------------- */
long long get_time_ns()
{
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (long long)ts.tv_sec * 1000000000LL + ts.tv_nsec;
}


/* -----------------------------------------------
 * measure_access_time()
 * 
 * Reads memory in strides (jumps of 64 bytes)
 * across a buffer of given 'size'.
 *
 * Returns average time per read in nanoseconds.
 * ----------------------------------------------- */
long long measure_access_time(char *buffer, int size)
{
    int i;
    volatile char val = 0;
    long long start, end;
    int mask = size - 1;   /* Used to wrap around within the buffer */

    /* --- Warm up: load data into cache before measuring --- */
    for (i = 0; i < size; i += CACHE_LINE)
        buffer[i] = (char)i;

    /* --- Measure: read memory repeatedly and time it --- */
    start = get_time_ns();

    for (i = 0; i < REPEAT; i++)
        val += buffer[(i * CACHE_LINE) & mask];

    end = get_time_ns();

    /* Prevent compiler from removing the loop (use val) */
    buffer[0] = val;

    /* Return average nanoseconds per read */
    return (end - start) / REPEAT;
}


/* -----------------------------------------------
 * classify_cache()
 * 
 * Looks at the time and tells you which cache
 * level is being used.
 * ----------------------------------------------- */
const char* classify_cache(long long ns)
{
    if (ns <= 4)   return "L1 Cache  (very fast)";
    if (ns <= 15)  return "L2 Cache  (fast)";
    if (ns <= 50)  return "L3 Cache  (medium)";
    return              "Main RAM  (slow - exceeded all cache)";
}


/* -----------------------------------------------
 * print_separator()
 * Just prints a divider line for neat output.
 * ----------------------------------------------- */
void print_separator()
{
    printf("+--------------+----------+-------------------------------+\n");
}


/* -----------------------------------------------
 * MAIN
 * ----------------------------------------------- */
int main()
{
    char *buffer;
    int size;
    long long time_ns;
    long long prev_time = 0;

    /* Allocate the largest buffer we will test */
    buffer = (char *)malloc(MAX_BUFFER);
    if (buffer == NULL) {
        printf("ERROR: Could not allocate memory!\n");
        return 1;
    }

    /* Fill buffer with zeros to start clean */
    memset(buffer, 0, MAX_BUFFER);

    /* Print header */
    printf("\n");
    printf("  CPU CACHE SIZE DETECTOR\n");
    printf("  Reads memory at different sizes and measures speed.\n");
    printf("  Big jump in time = you exceeded that cache level.\n");
    printf("\n");

    print_separator();
    printf("| Buffer Size  | Time(ns) | Cache Level                   |\n");
    print_separator();

    /*
     * Loop: start at 1 KB, double each time, up to 64 MB
     * 
     * Sizes tested: 1K, 2K, 4K, 8K, 16K, 32K, 64K, 128K,
     *               256K, 512K, 1M, 2M, 4M, 8M, 16M, 32M, 64M
     */
    for (size = 1 * KB; size <= MAX_BUFFER; size *= 2)
    {
        /* Measure how fast we can read this much memory */
        time_ns = measure_access_time(buffer, size);

        /* Format the size nicely (show KB or MB) */
        if (size < MB)
            printf("|  %6d KB   |  %5lld ns | %-30s|\n",
                   size / KB, time_ns, classify_cache(time_ns));
        else
            printf("|  %6d MB   |  %5lld ns | %-30s|\n",
                   size / MB, time_ns, classify_cache(time_ns));

        /* If time jumped a lot, a cache boundary was crossed */
        if (prev_time > 0 && time_ns > prev_time * 2)
        {
            printf("|                                                            |\n");
            printf("|  *** TIME JUMPED %.1fx — cache boundary crossed! ***       |\n",
                   (double)time_ns / prev_time);
            printf("|                                                            |\n");
        }

        prev_time = time_ns;
    }

    print_separator();

    printf("\n");
    printf("  GUIDE TO READING RESULTS:\n");
    printf("  - Look at which size causes the time to suddenly JUMP UP\n");
    printf("  - That size = the boundary between two cache levels\n");
    printf("  - Example: if time jumps at 256 KB → your L2 cache is ~256 KB\n");
    printf("\n");

    free(buffer);
    return 0;
}
