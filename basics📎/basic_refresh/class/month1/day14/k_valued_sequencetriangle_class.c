#include <stdio.h>

int main()
{
    int n = 5;
    
    int k = n;
    for ( int i = 1; i <= n ; i++ )
    {
            k = n;
        for ( int j = 1 ; j <= n ; j++ )
        {   

            if ( i >= j )
            {

                printf("%d",k);
                k--;
            }

        }
            printf("\n");
    }
}
