#include<stdio.h>
#define LARGEST(a,b,c) ((a)>(b)? ((a)>(c)?(a):(c)):((b)>(c)?(b):(c)))
int main()
{
  printf("Enter a,b,andc : ");
  int a,b,c;
  scanf("%d %d %d",&a,&b,&c);

  printf("Largest is %d\n",LARGEST(a, b, c));
}
