#include <stdio.h>
void oct (int a)
{
    if (a >= 1)
    {
        oct(a/8);
    printf("%d",a%8);
    }
    else
    {
        printf("0");
    }

}

int main()
{
    int n = 5;

    printf("Enter an Decimal value : ");
    scanf("%d",&n);
    oct(n);
}

