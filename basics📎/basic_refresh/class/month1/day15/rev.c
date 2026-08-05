#include<stdio.h>
int main()
{
    int n = 4;

    for ( int i = 1 ; i<= n; i++ )
    {
        for ( int j = 1 ; j <= n ; j++ )
        {
            if ( j >= i  )
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        for ( int j = 1 ; j <= n - 1 ; j++ )
        {
            if ( i+j <= n )
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
