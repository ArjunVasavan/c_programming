#include <stdio.h>
void bin (int a)
{
    if (a > 1)
    {
        bin(a/2);
    printf("%d",a%2);
    }
    else
    {
        printf("1");
    }

}

int main()
{
    int n = 5;

    printf("Enter an Decimal value : ");
    scanf("%d",&n);
    bin(n);
}

