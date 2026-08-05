#include<stdio.h>
int main()
{
    int n;
    int odd;
    printf("Enter N : ");
    scanf("%d",&n);
    int temp = n;

    for (int i = 1 ; i <= n ;  i++)
    {
        for(int j = 1 ; j <= (temp - i) ; j++)
        {
            printf(" ");
        }

        odd = (2*i) - 1;

        for(int k = 1; k <= odd ; k++)
        {
            printf("*");
        }


    printf("\n");
    }
}
