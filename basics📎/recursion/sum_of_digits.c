#include <stdio.h>

int digitsum(int n , int sum)
{
    int ret;

    if ( n != 0 )
    {
        sum = sum + (n%10);
        n = n/10;
        
        return digitsum(n , sum);

    }

    return sum;
}

int main()
{
    int n;
    printf("Enter an number to digit sum : --> ");
    scanf("%d",&n);
    printf("%d",digitsum(n,0));
    printf("\n");
}

