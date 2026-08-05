#include <stdio.h>
#define MACRO(num,bits) ((num) = ( (num >> bits) | ((num & ( (1 << bits)-1))<< (32 - bits))  ))
void print_b(int num)
{
  for ( int i = 31 ; i >= 0 ; i-- )
  {
    if (( num & ( 1 << i )) == 0 )
    {
      printf("0");
    }
    else 
    {
      printf("1");
    }
  }
}
int main()
{
  unsigned int num,bits;
  printf("Enter the number : ");
  scanf("%d",&num);

  printf("Enter the bits : ");
  scanf("%d",&bits);

  MACRO(num,bits);

  printf("RESULT : %d\n",num);

  print_b(num);
}
