#include<stdio.h>
int main()
{
	int n1,n2,sum = 0;

	printf("Enter n1 and n2 :");

	scanf("%d %d",&n1,&n2);

	int i = 0;

	while (i < n1)
	{
		sum+=n2;
		i++;
	}

	printf(" result = %d \n",sum);
}
