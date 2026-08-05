#include<stdio.h>
int main()
{
    int n;
    int rev = 0;
    int rem;
    int op = 0;

    printf("Enter an Number : ");
    scanf("%d",&n);

 
    while(n > 0)
    {
        rem = n % 10;

        if ( rem == 0 )
        {
            rem = 1;
        }

        rev = (rev * 10) + rem;

        n = n / 10;
    }

    while( rev > 0 )
    {
        rem = rev % 10;

        op = (op * 10 )+ rem;

        rev = rev /10;

    }



    
    printf("%d \n",op);

}
    
