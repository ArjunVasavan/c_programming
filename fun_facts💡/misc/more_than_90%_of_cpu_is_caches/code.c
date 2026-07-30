#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define ROWS 4096
#define COLS 4096

static int matrix[ROWS][COLS];

static double ms_since(struct timespec start) {
    struct timespec end;
    clock_gettime(CLOCK_MONOTONIC, &end);
    return (end.tv_sec - start.tv_sec) * 1000.0
         + (end.tv_nsec - start.tv_nsec) / 1e6;
}

int main(void) {
    struct timespec t0;
    long long sum = 0;

    for (int r = 0; r < ROWS; r++)
        for (int c = 0; c < COLS; c++)
            matrix[r][c] = r + c;

    /* CACHE FRIENDLY: row-major (sequential memory access) */
    sum = 0;
    clock_gettime(CLOCK_MONOTONIC, &t0);
    for (int r = 0; r < ROWS; r++)
        for (int c = 0; c < COLS; c++)
            sum += matrix[r][c];
    double friendly_ms = ms_since(t0);
    printf("Cache-friendly  (row-major): %8.2f ms   sum=%lld\n", friendly_ms, sum);

    /* CACHE HOSTILE: col-major (jumps 16KB between each access) */
    sum = 0;
    clock_gettime(CLOCK_MONOTONIC, &t0);
    for (int c = 0; c < COLS; c++)
        for (int r = 0; r < ROWS; r++)
            sum += matrix[r][c];
    double hostile_ms = ms_since(t0);
    printf("Cache-hostile (col-major):  %8.2f ms   sum=%lld\n", hostile_ms, sum);

    printf("\nSpeedup from cache: %.1fx faster\n", hostile_ms / friendly_ms);

    /* BONUS: stride experiment */
    printf("\nStride experiment:\n");
    int *flat = (int *)matrix;
    int total = ROWS * COLS;
    int strides[] = {1, 2, 4, 8, 16, 64, 256, 1024};
    for (int s = 0; s < 8; s++) {
        int stride = strides[s];
        sum = 0;
        clock_gettime(CLOCK_MONOTONIC, &t0);
        for (int i = 0; i < total; i += stride)
            sum += flat[i];
        printf("  stride %4d: %7.2f ms\n", stride, ms_since(t0));
    }

    return 0;
}
