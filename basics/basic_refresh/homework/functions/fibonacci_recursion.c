#include <stdio.h>

void fibon (int first,int second,int fib,int n)
{
    if ( n > 0 )
    {
        printf("%d ",fib);
        second = first;
        first = fib;
        fib = first+second;

        return fibon(first,second,fib,n-1);
    }

}
int main()
{
    printf("Enter the limit 'n' -->");
    int n;
    scanf("%d",&n);
    fibon(1,1,0,n);
    printf("\n");
}

