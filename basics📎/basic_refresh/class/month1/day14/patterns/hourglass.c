#include<stdio.h>

int main()
{
    int n;
    printf("Enter an 'n' : ");
    scanf("%d",&n);

    for ( int i = 0 ; i < n ; i++ )
    {
        for ( int j =  0; j < i ; j++ )
        {
            printf(" ");
        }
        for ( int k = 0 ; k < (n - i) ; k++ )
        {
            printf("* ");
        }
        printf("\n");
    }

    for ( int i = 2 ; i <= n ; i++ )
    {
        for ( int j = 1 ; j <= ( n - i ) ; j++ )
        {
            printf(" ");
        }
        for ( int k = 1 ; k <= i ; k++ )
        {
            printf("* ");
        }
        printf("\n");
    }
}
