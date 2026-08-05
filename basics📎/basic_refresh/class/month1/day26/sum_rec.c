#include <stdio.h>

int totsum(int n,int sum)
{
    int rem = 0;
    if ( n > 0 )
    {
        rem = n%10;
        sum = sum+rem;
        return totsum(n/10,sum);
    }
    else
    {
        return sum;
    }

}

int main()
{
    int n  = 1234;
    int sum = 0;

    printf("%d",totsum(n,sum));

}

