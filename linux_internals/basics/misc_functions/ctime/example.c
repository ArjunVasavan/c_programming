#include <stdio.h>
#include <time.h>

int main(void)
{
    time_t now = time(NULL);

    printf("Current time: %s", ctime(&now));

    return 0;
}

