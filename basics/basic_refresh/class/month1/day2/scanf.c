#include<stdio.h>
int x,y;
char c1,c2;
float f1,f2;
double d1,d2;
int main(){
printf(" Enter an number x and y = \n");
scanf("%d %d",&x,&y);
printf("you have entered %d and %d \n", x, y);


printf("Enter an character c1 and c2 = \n");
scanf("%c %c",&c1,&c2);
printf("you have entered %c and %c \n", c1, c2);


printf("Enter an number f1 and f2 = \n");
scanf("%f %f",&f1,&f2);
printf("you have entered %f and %f \n", f1, f2);


printf("Enter an double d1 and d2 =  \n");
scanf("%lf %lf",&d1,&d2);
printf("you have entered %lf and %lf \n", d1, d2);
}
