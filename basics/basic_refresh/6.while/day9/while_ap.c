#include<stdio.h>
int main()
{
	int start,diff,n,count = 0;

	printf("Enter start and difference :");

	scanf("%d %d",&start,&diff);

	printf("Enter n :");
	scanf("%d",&n);

	while (count < n)
	{
		printf("%d ",start);
		start+=diff;
		count++;
	}

}
