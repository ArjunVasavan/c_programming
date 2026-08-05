#include<stdio.h>

int main()
{
    int n = 4 ;

    for ( int i = n ; i > 0 ; i-- )
    {
        if ( i == n )
        {
            for ( int j =1 ; j <= n ; j++)
            {
                printf("* ");
            }

        }

        else if ( i < n )
        {
            for ( int k = 1 ; k <= n - i ; k++ )
            {
                printf("0");
            }

            printf("*");

            for ( int l = n-2 ; l > 0  ; l--  )
            {
                for ( int m = 1 ; m <= (2*l)+1 ; m++)
                {
                    printf("0");
                }
            }
        }
            



            printf("\n");
    }
}
