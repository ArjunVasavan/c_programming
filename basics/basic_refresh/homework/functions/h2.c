#include <stdio.h>

int fun (int a)
{
    if (a > 0)
    {
        int ret = fun ( a - 1 );
        return ret + a ;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int x = 5;
    int ret = fun(x);
    printf("%d \n",ret);
}

