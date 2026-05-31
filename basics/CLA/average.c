#include<stdio.h>
#include<stdlib.h>

int main(int argc,char** argv)
{
    int i = 1;
    float sum = 0;
    while ( argv[i] != NULL )
    {
        sum+=atoi(argv[i]);
        i+=1;
    }
    sum/=(argc-1);
    printf("Average is %g\n",sum);
}
