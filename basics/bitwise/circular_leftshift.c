/*
--------------------------------------------------------------------------------




--------------------------------------------------------------------------------
*/

#include<stdio.h>


int circular_left(int, int);
int print_bits(int);

int main()
{
    int num, n, ret;
    
  printf("Enter the num:");
    scanf("%d", &num);
    
    printf("Enter n:");
    scanf("%d", &n);
    
    ret = circular_left(num, n);
    
    print_bits(ret);
}

int circular_left(int num,int n)
{
  unsigned int msb_side = (num & (~((1 << (32-n))-1)));

  msb_side = msb_side >> 32 - n ;

  int ret = num << (n);

  ret = ret | msb_side;

  return ret;
}

int print_bits(int ret )
{
  for ( int i = 31 ; i >= 0 ; i-- )
  {
    if (( ret &(1 << i)) == 0)
    {
      printf("0");
    }
  else 
  {
      printf("1");
  }

  }

  printf("\n");

  return 1;
}
