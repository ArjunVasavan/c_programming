#include<stdio.h>
int main()
{
	int n;
	printf("Enter the number : ");
	scanf("%d",&n);
	if ( (n % 3 == 0) && (n % 5 == 0))
	{
		printf("FIZZ BUZZ \n");
	}
	else if ( n  % 3 == 0)
	{
		printf("FIZZ \n");
	}
	else if (n % 5 == 0)
	{
		printf("BUZZ \n");
	}
	else
	{
		printf("INVALID INPUT \n");
	}
}
