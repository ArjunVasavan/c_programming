#include<stdio.h>
int main()
{
	int n;
	int rev = 0;
	int rem;
	printf("Enter n :");
	scanf("%d",&n);

	for(;n>0;)
	{
		rem = n%10;


		rev = rev + rem;


		n = n / 10;

	if (n > 0)
      	{
		rev=rev*10;
	}

	}
	printf(" output = %d \n",rev);
}
