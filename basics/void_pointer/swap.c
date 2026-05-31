#include<stdio.h>

void swap ( void * p1 , void * p2 ,int size )
{
  for ( int i = 0 ; i < size ; i ++ )
  {
    char temp = *((char*)p1);
    *((char*)p1) = *((char*)p2);
    *((char*)p2) = temp;
    *(char*)p1++;
    *(char*)p2++;
  } 

}
int main()
{
  int a, b;

  a = 10;
  b = 20;

  float f1,f2;
  f1 = 1.3;
  f2 = 6.6;
  printf("a is %d and b is %d \n",a,b);
  swap(&a,&b,4);

  printf("after swapping ->> f1 is %f and f2 is %f \n",f1,f2);
  swap(&f1,&f2,4);

  printf("after swapping ->> f1 is %f and f2 is %f \n",f1,f2);
}
