#include <stdio.h>

int main ()
{
    int n = 5;

    for ( int i = 1 ; i <= n ; i++ )
    {
        for ( int j = 1 ; j <= n ; j++ )
        {
            if ( i == j )
            {
                printf("%d",i);
            }
            else if ( j == (n - i + 1) )
            {
                printf("%d",j);
            }
            else
            {
                printf(" ");
            }
        }

        printf("\n");
    }
}
