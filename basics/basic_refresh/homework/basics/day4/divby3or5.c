#include<stdio.h>
int divthree(int n);

int main(){
int n;
printf("Enter an Number : ");
scanf("%d",&n);

if (n%5 == 0)	
{
	printf("its Dividable by 5");
	divthree(n);

}
else if (n%3== 0){

	printf("its dividable by 3 only \n");
}
else
{
	printf(" dont put symbols nigga ! \n");
}
}
int divthree( int n){
	if (n % 3 == 0)
	{
		printf(" and 3  \n");
	}
	else {
		printf(" only \n");
	}




}
