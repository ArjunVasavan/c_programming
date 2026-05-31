#include<stdio.h>
int main()
{
	int n;
	int org;
	int rev = 0;
	int rem;
	printf("Enter n :");
	scanf("%d",&n);
	org = n;

	while( n != 0 )
	{
		rem = n%10;


		rev = rev*10 + rem;


		n = n / 10;


	}
	if ( org == rev)
	{

		printf("Its an Palindrome");
	
	}
	else
	{
		printf("Not palindrome");
	}
}
