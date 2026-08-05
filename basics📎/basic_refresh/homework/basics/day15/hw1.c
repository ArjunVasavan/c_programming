#include<stdio.h>

int main()
{

    int n;

    printf("Enter a number : ");
    scanf("%d",&n);

    for ( int i = 1 ; i <= n ; i++ )
    {
        int k = 1;

        for ( int j = 1 ; j <= n ; j++ )
        {
            if ( j >= i )
            {
                printf("%d ",k);
            }
            else
            {
                printf("  ");
            }
            k++;
        }

        int l = n - 1;

        for ( int j = 1 ; j <= n - 1; j++ )
        {
            if ( i + j <= n )
            {
                printf("%d ",l);
            }

            l--;

        }

        printf("\n");


    }
}
