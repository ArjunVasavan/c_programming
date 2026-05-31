#include<stdio.h>
#include<stdio_ext.h>
int main()
{
	int n1,n2;
	char op;
	printf("Enter two numbers :");
	scanf("%d %d",&n1,&n2);

	printf("Enter operation");
	__fpurge(stdin);
	scanf("%c",&op);

	printf("%d %c %d = \n", n1,op,n2);

}

