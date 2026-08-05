#include<stdio.h>
int main()
{
	int n;
	int c = 0;
	char temp = 64;
	char res = 0;
	printf("Enter n :");
	scanf("%d",&n);

	for (int i = 1; i <= n ; i ++)
	{	
		c = 0;

		for (; c < i ;)
		{
			res = temp + 1;
			printf("%c ",res);
			temp = res;
			c +=1 ;
		}
	printf("\n");
	}

}
