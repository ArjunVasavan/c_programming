#include <stdio.h>

void fact ( int n ,int* result)
{
    if ( n>0)
    {
        *result = (*result)* (n);
        n--;
        fact(n,result);
    }
}

int main()
{
    int n;
    int result = 1 ;
    printf("Enter the 'n' Value : ");
    scanf("%d",&n);

    fact(n,&result);

    printf("Result is --> %d",result);
    printf("\n");
}

