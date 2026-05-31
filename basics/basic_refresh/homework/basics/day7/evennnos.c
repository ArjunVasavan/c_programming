#include<stdio.h>
int main()
{
	int n;
	int c = 0;
	printf("Enter n :");
	scanf("%d",&n);

	for (int i=1 ; c < n ; i ++)
	{
		if (i %2 == 0)
		{
			printf("%d   ",i);
			c+=1;
		}
	}


}
