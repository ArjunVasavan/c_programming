#include<stdio.h>
int main()
{
    int n1 , n2 ;
    int mult = 0;
    printf("Enter an Number 1: ");
    scanf("%d",&n1);

    printf("Enter an Number 2: ");
    scanf("%d",&n2);
    int i = 0;

    while ( i < n1 )
    {
        mult = mult + n2 ;

        i++;

    }

    printf("%d ",mult);
}
