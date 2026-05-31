#include<stdio.h>
int main()
{
    int n;
    printf("Enter an Number : ");
    scanf("%d",&n);

    int var = 65 ;

    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 1 ; j <= i ; j++)
        {
            printf("%c ",var);

            var+=1;
        }
        printf("\n");
    }
}
