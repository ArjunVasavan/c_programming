
#include<stdio.h>
int main()
{
  unsigned int hex;
  printf("Enter the number in the hexadecimal format: ");
  scanf("%X",&hex);

  int n;

  printf("Enter n value:");
  scanf("%d",&n);

  int set = hex | (1 << n);
  int clear = hex & ~( 1 << n );
  int get = (hex & ( 1 << n )) >> n;

  printf("Result after setting nth bit is :%X\n",set);
  printf("Result after clearing nth bit is :%X\n",clear);
  printf("Get bit at nth position is: %d\n",get);

}
