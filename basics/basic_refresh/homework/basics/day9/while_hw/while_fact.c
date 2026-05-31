#include<stdio.h>
int main()
{
    int n;
    int fact = 1 ;
    printf("Enter an Number : ");
    scanf("%d",&n);

    int i = 1;

    while ( i <= n )
    {
        fact = fact * i ;

        i++;

    }

    printf("%d ",fact);
}
