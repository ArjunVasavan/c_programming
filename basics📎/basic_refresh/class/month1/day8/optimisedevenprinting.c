#include<stdio.h>
int main()
{
	int n;
	printf("Enter n value : ");
	scanf("%d",&n);

	for ( int i = 2 ; i <=n ; i+=2)
	{
		printf("%d ",i);
	}

}
