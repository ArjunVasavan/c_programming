#include<stdio.h>
int main()
{
	int n;
	int c = 0;
	int temp = 0;
	int res = 0;
	printf("Enter n :");
	scanf("%d",&n);

	for (int i = 1; i <= n ; i ++)
	{	
		c = 0;

		for (int j = 1 ; c < i ; j ++ )
		{
			res = temp + 1;
			printf("%d ",res);
			temp = res;
			c +=1 ;
		}
	printf("\n");
	}

}
