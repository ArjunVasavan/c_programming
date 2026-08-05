#include <stdio.h>
int main()
{
    int n;

    printf("Enter a number : ");

    scanf("%d",&n);
    
    int i,j;

    for ( i = n ; i > 0 ; i-- )
    {
        for( j = n ; j >= i ; j-- )
        {
            if  (j == n)
            {
                printf("%d ",j);
            }
            else {
                printf("%d ",j);
            }

        }
            printf("\n");
    }
}
