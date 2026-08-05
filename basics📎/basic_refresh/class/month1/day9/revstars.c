#include<stdio.h>
int main()
{
	int n;
	printf("Enter n :");
	scanf("%d",&n);

	for (int i = n; i >= 0 ; i -- )
	{
		for (int j = 0 ; j <= i ; j ++ )
		{
			printf("*");
		}
	printf("\n");
	}

}
