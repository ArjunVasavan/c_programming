#include <stdio.h>

int circular_right(unsigned int, int);
int print_bits(int);

int main()
{
    int num, n, ret;
    
    printf("Enter the num:");
    scanf("%d", &num);
    
    printf("Enter n:");
    scanf("%d", &n);
    
    ret = circular_right(num, n);
    
    print_bits(ret);
}

int circular_right(unsigned int num, int n )
{
  return  ((( num >> (n) ) | ( (num & (~((1 >> (n))-1))) ) << (31 - n )));
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
