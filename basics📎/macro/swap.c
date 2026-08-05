#include<stdio.h>

#define swap(x,y) \
        x = x ^ y; \
        y = x ^ y;  \
        x = x ^ y;   

int main()
{
   int x = 5 ;
   int  y = 10;

  swap(x,y);
  printf("X = %f \n",x);
  printf("Y = %f \n",y);
}
