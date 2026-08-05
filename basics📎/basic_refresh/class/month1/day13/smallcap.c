
#include<stdio.h>

int main()
{
    int n;
    char ch = 'a'; 
    printf("Enter N value :");

    scanf("%d",&n);

    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 1 ; j <= n ; j++)
        {   
            if ( (i + j)%2 == 0 )
            {
            printf("%c ",ch-32);
            }
            else
            {
                printf("%c ",ch);
            }
            ch+=1;
        }
    printf("\n");
    }
}
