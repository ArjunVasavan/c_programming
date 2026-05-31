#include<stdio.h>
int main(){
char ch;
printf("Enter the character : ");
scanf("%c",&ch);

if (ch >= 48 && ch <=57 )	
{
	printf("its an digit character \n");
}
else if (ch >= 65 && ch <= 90){

	printf("its an uppercase \n");
}
else if ( ch >= 97 && ch <= 122){
	printf("its an lowercase \n");
}
else
{
	printf(" dont put symbols nigga ! \n");
}
}
