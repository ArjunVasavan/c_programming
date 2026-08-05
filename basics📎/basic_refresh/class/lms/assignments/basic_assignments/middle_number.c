#include <stdio.h>
int main()
{
    int n1,n2,n3;
    printf("Enter the Three numbers n1, n2, n3 : ");
    scanf("%d %d %d",&n1,&n2,&n3);
    if (n1 > n2)
    {
        if(n1 < n3)
        {
            printf("The middle number is %d",n1);
        }
        else if (n2 > n3)
        {
            printf("The middle number is %d",n2);
        }
        else
        {
            printf("The middle number is %d",n3);
        }
    }
    else 
    {
        if (n1 > n3)
        {
            printf("The middle number is %d",n1);
        }
        else if (n3 > n2)
        {
            printf("The middle number is %d",n2);
        }
        else 
        {
            printf("The middle number is %d",n3);
        }
    }
}

