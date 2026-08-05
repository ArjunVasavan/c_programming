#include <stdio.h>

int count (int n , int c)
{
    if ( n != 0 )
    {
    return count(n/10,c+=1);
    
    }
    return(c);
}

int main()
{
    int n = 0;
    printf("Enter a number -->");
    scanf("%d",&n);
    printf("%d",count(n,0));
    printf("\n");
}

