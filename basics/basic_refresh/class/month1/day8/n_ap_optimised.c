#include<stdio.h>
int main()
{
	int l,s,d;
	int count = 0;
	printf("Enter starting number : ");
	scanf("%d",&s);
	printf("Enter the difference : ");
	scanf("%d",&d);
	printf("Enter the limit : ");
	scanf("%d",&l);

	for ( ; count < l ; s+=d)
	{
		printf("%d ",s);
		count+=1;
	}

}
