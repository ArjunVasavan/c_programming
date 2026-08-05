#include <stdio.h>
int main()
{
    int rem;
    int rev = 0;
    int n;
    int n1;
    int n2;
    int op = 0;


    printf("Enter an Number to Swap : ");
    scanf("%d",&n);

    n1 = n % 10;

    while ( n != 0 )
    {
        rem = n % 10;
        rev = (rev * 10)+rem;
        n = n / 10;

    }

    n2 = rev % 10;

    rev = rev / 10;

    op = (op*10)+n1;

    while (rev != 0)
    {
        rem = rev % 10;

        op = (op*10)+rem;

        rev = rev / 10;

        if (rev < 9) 
        {
            op = (op * 10)+n2;
            rev = 0;
        }


    }
    

    printf("The numbers first and last digit is swapped resulting : %d \n",op);
}
