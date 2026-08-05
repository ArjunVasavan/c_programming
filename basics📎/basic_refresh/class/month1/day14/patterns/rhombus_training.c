#include<stdio.h>

int main ()
{
    int n ;

    printf("Enter an Number 'n' : ");

    scanf("%d",&n);

    for ( int i = n ; i >= 1 ; i-- )
    {
        for (int j = 1 ; j <= (n - i) ; j++)
        {
            printf("  ");
        }
        for ( int k = 1 ; k < n ; k++ )
        {
            printf("*");
        }
        printf("\n");
    }
}
