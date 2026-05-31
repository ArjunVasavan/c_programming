#include<stdio.h>
int main(){
int a;
int b;
int c;
printf("Enter  Base 'a' = ");
scanf("%d",&a);
printf("Enter Height 'b' = ");
scanf("%d",&b);
printf("Enter Hyportnuse 'c' = ");
scanf("%d",&c);
if ( ((a*a)+(b*b))  == c*c     ){

 	printf("its an right angled triangle \n");


}
else{



	printf("its not an right angled triangle");

}


}
