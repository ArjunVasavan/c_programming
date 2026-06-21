#include<stdio.h>
int main()
{
	int n;
	int count = 0;
	printf("Enter n value : ");
	scanf("%d",&n);

	for ( int i = 2 ; count <n ; i+=2)
	{
		printf("%d ",i);
		count+=1;
	}

}
