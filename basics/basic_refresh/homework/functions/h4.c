#include <stdio.h>

int fun (int x)
{
    if (x <= 1)
    {
        return 0 ;

    }
    else if (x % 2  == 0)
    {
        return fun(x/2);
    }

    else
    {
        return fun ((x - 1)/2);
    }
}

int main()
{
    int x = 5;
    int ret = fun(x);
    printf("%d \n",ret);
}

