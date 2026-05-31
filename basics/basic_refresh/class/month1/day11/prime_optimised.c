#include<stdio.h>
int main()
{
    int num;
    printf("Enter 'n' value : ");
    scanf("%d",&num);
    int i  = 1;
    for ( i = 2; i*i <= num ; i++)
    {
        if (num%i == 0)
        {
            break;
        }
    }
    if (i*i > num)
    {
        printf("Its an Prime \n");
    }
    else
    {
        printf("Its Not an Prime \n");
    }
}
