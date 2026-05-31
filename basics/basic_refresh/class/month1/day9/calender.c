#include<stdio.h>
int main()
{
	int start , n , result;
	printf("Enter starting day : ");
	scanf("%d",&start);

	printf("Enter Nth day : ");
	scanf("%d",&n);

	if ( start <= 7 && n <= 365)
	{

	result = (start + (n - 1)) % 7 ;

	switch(result)
	{
		case 0 : 
			printf("Sunday");
			break;
		case 1 : 
			printf("Monday");
			break;
		case 2 : 
			printf("Tuesday");
			break;
		case 3 : 
			printf("Wednesday");
			break;
		case 4 : 
			printf("Thursday");
			break;
		case 5 : 
			printf("Friday");
			break;
		case 6 : 
			printf("Saturday");
			break;
	}
	}
	else {
		printf("Enter valid details");
	}
}
