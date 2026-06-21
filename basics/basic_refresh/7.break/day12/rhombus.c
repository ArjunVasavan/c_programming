#include<stdio.h>

int main()
{
    int n;

    int odd;

    printf("Enter the N value : ");

    scanf("%d",&n);
    
    for (int i = 1 ; i <= n ; i++ )
    {
        for ( int j = 1 ; j <= (n - i) ; j++)
        {
            printf(" ");
        }
        odd = (2*i)-1;
        for(int k = 1 ; k <= odd ; k++)
        {
            printf("*");

        }
        printf("\n");
    }
    for(int i = n - 1 ; i > 0 ; i--)
    {
        for ( int j = 1 ; j <= (n-i) ; j++  )
        {
            printf(" ");
        }
        odd = (2*i)-1;
        for(int k = 1 ; k <= odd ; k++ )
        {
            printf("*");
        }

        printf("\n");

    }
}
