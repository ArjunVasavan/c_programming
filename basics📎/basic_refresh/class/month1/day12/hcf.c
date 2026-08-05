#include <stdio.h>
int main ()
{
    int n1,n2,mult;

    printf("Enter an number 1 :");
    scanf("%d", &n1);

    printf("Enter an number 2 :");
    scanf("%d", &n2);

    int i;   

    if (n1 > n2)
    {
        i = n2/2;
    }
    else
    {
        i = n1/2;
    }
    for (; i>= 1; i--)
    {
        if((n1%i==0) && (n2%i == 0))
        {
            printf("HCF is %d",i);

            break;
        }
    }


}
