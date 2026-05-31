#include <stdio.h>
int main(int argc, char** argv)
{
    volatile long long int wait;

    unsigned char bit = 0;

    while (1) {
    
        bit = !bit;

        printf("The bit is now : %d\r",bit);

        fflush(stdout);

        for ( wait = 0xFFFFFFFFFFFFFFFF; wait--;);
    }
}
