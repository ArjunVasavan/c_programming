#include <stdio.h>

int fact (int a)
{
    if ( a > 0 )
    {
        return fact(a-1)*a;
    }
    else
    {
        return 1;
    }
}

int main()
{
    int n = 5;
    printf("%d",fact(n));
}

