#include <stdio.h>

int fun (int x)
{
    if (x == 0)
    {
        return 0 ;

    }
    else if (x ==1)
    {
        return 1;
    }

    else
    {
        return fun(x - 1) + fun ( x - 2 );
    }
}

int main()
{
    int x = 5;
    int ret = fun(x);
    printf("%d \n",ret);
}

