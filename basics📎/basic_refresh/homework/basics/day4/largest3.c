#include<stdio.h>
int main(){
int n1;
int n2;
int n3;
printf("Enter the number n1 n2 n3 : ");
scanf("%d %d %d",&n1,&n2,&n3);

if (n1 > n2 && n1 >n3 )	
{
	printf(" n1 \n");
}
else if (n2 > n1 && n2 > n3 ){

	printf(" n2 \n");
}
else
{
	printf(" n3 \n");
}
}
