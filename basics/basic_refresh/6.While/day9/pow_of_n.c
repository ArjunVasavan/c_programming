#include<stdio.h>
int main ()
{
	int exp;
	int c = 0;
	int temp = 1;
	int pow = 0;
	int base;
	printf("Enter the exponent : ");
	scanf("%d",&exp);
	printf("Enter the base : ");
	scanf("%d",&base);
	if (exp > 0)
	{	
		if (exp ==1)
		{
	       		printf(" 1 \n");
		}
		else 
		{       printf(" 1,");
	
			for ( int i = 0 ; c < exp ; i ++ )
			{
				pow = base * temp;
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
