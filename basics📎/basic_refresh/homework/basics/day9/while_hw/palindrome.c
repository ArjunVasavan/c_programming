#include <stdio.h>

int main ()
{
	int n;
	int rev = 0;
	int rem;
	printf("Enter an Number = ");
	scanf("%d",&n);
    int temp = n;

	while ( n > 0) 
	{
		rem =  n % 10;

		rev = rev * 10 + rem ;

		n = n / 10 ;
	
	}
    if (rev == temp)
    {
        printf("Its an Palindrome");
    }
    else
    {
        printf("Its no a palindrome");
    }
	
}
