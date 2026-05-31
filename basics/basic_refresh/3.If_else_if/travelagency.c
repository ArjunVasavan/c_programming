#include<stdio.h>
int main(){
int n;
printf("Enter the age : ");
scanf("%d",&n);

if (n >= 18  )	
{
	printf(" your free to tavel \n");
}
else if (n >= 60 ){

	printf(" half the price \n");
}
else if ( n >= 60 && n <= 80 ){
	printf(" pay full price \n");
}
else
{
	printf(" your not eligible ! \n");
}
}
