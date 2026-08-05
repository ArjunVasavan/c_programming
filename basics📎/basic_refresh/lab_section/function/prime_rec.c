#include <stdio.h>

int prime(int x)
{
    int n = x;
    int v;
    if ( n >= 2 && n < x )
    {
        v =  prime(n - 1);
            if ( x % v == 0 )
            {
                return 1;
            }
    }

    return 0;

}

int main()
{
    int n = 4;

    prime(n) ? printf("Its not an prime ") : printf("Its an Prime");
}

