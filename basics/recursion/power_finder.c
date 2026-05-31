#include <stdio.h>

int power(int n , int p )
{
    int ret;
    if ( p > 1 )
    {
        ret = power(n,p-1)*n;
    }
    else
    {
        return n;
    }

    return ret;
}

int main()
{
    int n;
    int p;

    printf("Enter base number --> ");
    scanf("%d",&n);
    printf("Enter power  --> ");
    scanf("%d",&p);

    printf("%d\n",power(n,p));

}

