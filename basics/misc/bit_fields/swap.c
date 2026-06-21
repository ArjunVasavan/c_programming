#include <stdio.h>
union u 
{

  unsigned int variable;

  struct
  {
    unsigned char nibble1 : 4;
    unsigned char nibble2 : 4;
  };

};
int main()
{

  union u result;
  printf("Enter the hexadecimal:");
  scanf("%x",&result.variable);

  result.nibble1 = result.nibble1 ^ result.nibble2;
  result.nibble2 = result.nibble1 ^ result.nibble2;
  result.nibble1 = result.nibble1 ^ result.nibble2;
  
  printf("Result : %X\n",result.variable);
    
}
