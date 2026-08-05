#include <stdio.h>
#include <time.h>

int main(void)
{
    time_t now;

    now = time(NULL);

    printf("Seconds since Epoch: %ld\n", now);

    return 0;
}

