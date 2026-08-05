#include <stdio.h>

int fun (int a)
{
    int new = 0;
    if (a >0)
    {
        new = fun(a-1);
    }
    return a + new;
}

int main()
{
    int x = 3;
    int ret = fun(x);
    printf("%d",ret);
}

