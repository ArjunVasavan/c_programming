#include<stdio.h>
int main()
{
    int num,n;
    printf("Enter 'n' value (limit) : ");
    scanf("%d",&n);
    int i  = 1;
    for ( num = 2 ; num <= n ; num++ )
    {
        for ( i = 2; i*i <= num ; i++)
        {
            if (num%i == 0)
            {
                break;
            }
        }  

        if (i*i > num)
        {
            printf("%d ",num);
        }


    }

    printf("\n");

}
