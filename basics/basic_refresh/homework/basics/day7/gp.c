#include<stdio.h>
int main()
{
	int n;
	int c = 1;
	int input;
	int temp;
	int res = 0;
	int r;

	printf("Enter number to start GP : ");
	scanf("%d",&input);
	printf("Enter the common ratio : ");
	scanf("%d",&r);
	printf("Enter how much numbers should be shown : ");
	scanf("%d",&n);

	printf(" %d ,",input);
	temp = input;
	for ( int i = 0 ; c < n ; i ++)
	{
		res = temp * r;
		printf(" %d ,",res);
		temp = res;
		c+=1;


	}


}
