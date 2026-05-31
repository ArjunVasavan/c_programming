#include<stdio.h>
int main(){
char ch,capch;
printf("Enter an CAPITAL LETTER :");
scanf("%c",&capch);
printf("ASCII number of the CAPITAL LETTER %hhd \n",capch);

ch = capch + 32;
printf("small letter of the letter you have entered is : %c \n",ch);

printf("ASCII number of the SMALL LETTER %hhd \n",ch);

}
