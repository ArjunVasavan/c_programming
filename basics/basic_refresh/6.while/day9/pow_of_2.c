#include<stdio.h>
int main ()
{
	int n;
	int c = 0;
	int temp = 1;
	int pow = 0;
	printf("Enter the N : ");
	scanf("%d",&n);
	if (n > 0)
	{	
		if (n ==1)
		{
	       		printf(" 1 \n");
		}
		else 
		{       printf(" 1,");
	
			for ( int i = 0 ; c < n ; i ++ )
			{
				pow = 2 * temp;
				printf(" %d,",pow);
				temp = pow;
				c+=1;
			}
			printf("\n");
		}
	}
	else
	{
		printf("Enter number greater than 0 \n");
	}
}
