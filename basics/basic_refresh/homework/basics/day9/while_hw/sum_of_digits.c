#include<stdio.h>

int main()
{
	int n;
	
	int sum = 0;

	int rem;

	printf("Enter n : ");
 
	scanf("%d",&n);

	while( n > 0)
	{
	  rem =	n % 10;

	  sum+=rem;

	  n = n / 10;
 
	}

	printf("%d \n",sum);
}
