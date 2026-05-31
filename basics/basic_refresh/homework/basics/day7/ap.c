#include<stdio.h>
int main()
{
	int n;
	int c = 1;
	int input;
	int temp;
	int res = 0;
	int d;

	printf("Enter number to start AP : ");
	scanf("%d",&input);
	printf("Enter the common Difference : ");
	scanf("%d",&d);
	printf("Enter how much numbers should be shown : ");
	scanf("%d",&n);

	printf(" %d ,",input);
	temp = input;
	for ( int i = 0 ; c < n ; i ++)
	{
		res = temp + d;
		printf(" %d ,",res);
		temp = res;
		c+=1;


	}


}
