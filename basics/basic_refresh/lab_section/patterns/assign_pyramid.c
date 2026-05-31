#include <stdio.h>

int main ()
{
    int n = 5;

    for ( int i = n ; i > 0 ; i-- )
    {
        for ( int j = i ; j <= n ; j++ )
        {
                    printf("%d ",j);

        }

        printf("\n");


    }
    for ( int i = 2 ; i <= n ; i++ )
    {
        for ( int j = i ; j <= n ; j++ )
        {
                    printf("%d ",j);

        }

        printf("\n");


    }
}
