#include <stdio.h>

int main()
{
    int n = 4;

    for ( int i = 1 ; i <= n ; i++ )
    {
        for ( int j = 1 ; j <= n ; j++ )
        {
            if ( i + j >=  n + 1 )
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }

        if ( i != 0 )
        {
            for ( int j = 1 ; j <= n - 1 ; j++ )
            {

                if ( i - 1 >= j )
                {
                    printf("*");
                }

            }
        }

        printf("\n");
    }
    
    int k = n - 1;

    for ( int i = 1 ; i <= k ; i++ )
    {
        printf(" ");
        for ( int j = 1 ; j <= k ; j++ )
        {
            if ( i <= j )
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }

        for ( int j = 1; j <= k - 1 ; j++ )
        {
            if ( i + j <= k  )
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }

        printf("\n");


    }
}
