#include<stdio.h>
int main(){
int n;
printf("Enter an Number : ");
scanf("%d",&n);

switch (n)
{
	case 1:
		printf("You have entered 1");
		break;
	case 2:
		printf("you have entered 2");
		break;
	default:
		printf("outside limit");
}

}
