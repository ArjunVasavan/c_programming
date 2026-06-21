#include<stdio.h>
int main()
{
	int l,s,d;
	printf("Enter starting number : ");
	scanf("%d",&s);
	printf("Enter the difference : ");
	scanf("%d",&d);
	printf("Enter the limit : ");
	scanf("%d",&l);

	for ( ; s < l ; s+=d)
	{
		printf("%d ",s);
	
	}

}
