#include<stdio.h>

int main()
{
    int n;
    int k = 1;
    printf("Enter N value :");

    scanf("%d",&n);

    for (int i = 1 ; i <= n ; i++)
    {
        k = n;

        for (int j = 1 ; j <= n ; j++)
        {
            if( i + j >= n+1 )
            {
            if ( j == n || (i + j) == n + 1 )
            {
                printf("%d",k);
            }
            else
            {
                printf(" ");
            }
            k--;

            }
        }
    printf("\n");
    }
}
