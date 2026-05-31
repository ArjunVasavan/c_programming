#include<stdio.h>
int main()
{
	int n;
	int product = 1;
	printf("Enter n :");
	scanf("%d",&n);

	for (int i=1 ; i <= n ; i ++)
	{
		product*=i;
	}

		printf("%d \n",product);

}
