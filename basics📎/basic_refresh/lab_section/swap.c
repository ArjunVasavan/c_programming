#include <stdio.h>

int main()
{
    int rem;
    int rev = 0;
    int n;
    int n1;
    int n2;
    int op = 0;
    int c = 0;

    printf("Enter a number to swap: ");
    scanf("%d", &n);

    int temp = n;

    n1 = n % 10;

    while (n != 0)
    {
        rem = n % 10;
        rev = (rev * 10) + rem;
        n = n / 10;
        c++;
    }

    n2 = rev % 10;
    rev = rev / 10; 

    op = (op * 10) + n1;

    for (int i = 1; i < c - 1; i++)
    {
        rem = rev % 10;
        op = (op * 10) + rem;
        rev = rev / 10;
    }

    op = (op * 10) + n2;

    printf("The number after swapping first and last digit is: %d\n", op);
}

