#include<stdio.h>

int main()
{
    int n;
    int k =  1;
    
    printf("Enter N value :");

    scanf("%d",&n);

    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 1 ; j <= n ; j++)
        {
            if ( j == 1 ||(i + j <= n + 1 ))
            {
                printf("%d",k);
                k++;
            }
            else
            {
                printf(" ");
            }
        }
    printf("\n");
    }
}
