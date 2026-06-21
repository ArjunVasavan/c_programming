#include<stdio.h>
int main(){
int n;
printf("Enter the grade : ");
scanf("%d",&n);

if (n <= 60)
{
	printf("D grade \n");
}
else if (n >= 60 && n<= 75){

	printf("C grade \n");
}
else if ( n >= 75 && n <= 90){
	printf("B grade \n");
}
else
{
	printf("A grade \n");
}
}
