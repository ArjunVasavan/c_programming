#include<stdio.h>
int main()
{
	int n1,n2;
	int mult = 0;
	printf("Enter n1 and n2 :");
	scanf("%d %d",&n1,&n2);

	for (int i=1 ; i <= n1 ; i ++)
	{
		mult+=n2;
	}

		printf("%d \n",mult);

}
