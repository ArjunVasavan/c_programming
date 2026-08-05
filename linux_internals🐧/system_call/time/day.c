#include <bits/types/struct_timeval.h>
#include <stdio.h>
#include <sys/time.h>
int main(int argc, char** argv){
    
    int variable;

    struct timeval tv;
    variable = gettimeofday(&tv,NULL);
    printf("Micro second : %lu\n",tv.tv_usec);
    printf("Second : %lu\n",tv.tv_sec);

}
