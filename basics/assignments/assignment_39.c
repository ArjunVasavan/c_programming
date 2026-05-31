#include <stdio.h>
#define MACRO(num,pos,bits) ( (num) = (num) ^ (((1<<bits)-1)<<(pos - bits + 1)) );
int main()
{
  int num,bits,pos;
  printf("Enter the number : ");
  scanf("%d",&num);
  printf("Enter the number of bits : ");
  scanf("%d",&bits);
  printf("Enter the position : ");
  scanf("%d",&pos);

  MACRO(num, pos, bits)

  printf("RESULT : %d\n",num);

}
