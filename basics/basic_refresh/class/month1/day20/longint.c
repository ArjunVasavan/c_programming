#include <stdio.h>

int main ()
{
    int x = 5;

    printf("size of x --> %lu \n",sizeof(x));

    long int y = 6;

    printf("size of long  y  --> %lu \n",sizeof(y));

    long long int z = 9;
    printf("size of long long int z  --> %lu \n",sizeof(z));
}
