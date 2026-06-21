#include<stdio.h>
int eveorodd(int n);

int main(){
int n;
printf("Enter an Number : ");
scanf("%d",&n);

if (n >= 0)	
{
	printf("its an Positive Number \n");
	eveorodd(n);

}
else if (n < 0){

	printf("its an Negative Number \n");
	eveorodd(n);
}
else
{
	printf(" dont put symbols nigga ! \n");
}
}
int eveorodd( int n){
	if (n % 2 == 0)
	{
		printf(" its also an even number \n");
	}
	else {
		printf(" its also an odd number \n");
	}




}
