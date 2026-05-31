#include <stdio.h>

int main()
{
    int n;
    int i,j;    
    printf("Enter a number :");
    scanf("%d",&n);

    for ( i = 1; i<= n; i++)
    {
        for ( j = 1 ; j<= i ; j++)
        {
            if ( j ==1 || i == j )
            {
                printf("%d ",j);
            }
            else
            {
                printf(" ");
            }
        }

        printf("\n");
    }
    
}
