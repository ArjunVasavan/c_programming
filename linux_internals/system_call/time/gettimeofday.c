#include <stdio.h>
#include <sys/time.h>
int main(int argc, char** argv)
{
    struct timeval variable;


    int tv = gettimeofday(&variable,NULL);

    printf("Time in usecond : %lu\n",variable.tv_usec);
    printf("Time in second : %lu\n",variable.tv_sec);

    
}
