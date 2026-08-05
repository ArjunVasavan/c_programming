#include<stdio.h>
int main()
{
	int x;
	int y;
	printf("Enter Number x =  ");
	scanf("%d",&x);
	float a = x;
	printf("Enter Number y =  ");
	scanf("%d",&y);
	float b = y;
	printf("Addition of %d with %d is : %d\n",x,y,x+y);
	printf("Substraction of %d with %d is : %d\n",x,y,x-y);
	printf("Multiplication of %d with %d is : %d\n",x,y,x*y);
	printf("Division of %d with %d is : %.2f\n",x,y,a/b);
	return 0;
}
