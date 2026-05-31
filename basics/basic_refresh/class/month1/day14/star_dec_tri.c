#include<stdio.h>

int main()
{
    int n;
    int k =  1;
    char ch = 65;
    
    printf("Enter N value :");

    scanf("%d",&n);

    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 1 ; j <= n ; j++)
        {
            if ( i <= j )
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
    printf("\n");
    }
}
