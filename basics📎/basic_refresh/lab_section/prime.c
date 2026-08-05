#include<stdio.h>
int main()
{
    int num;

    printf("Enter N : ");
    scanf("%d",&num);
    int i = 1;
    for (i = 2 ; i*i <= num ; i++)
    {
        if (num % i ==0)
        {
            break;
        }

    }
    if (i*i > num)
    {
        printf("Its an Prime");
    }
    else
    {
        printf("Its not an prime");
    }
}
