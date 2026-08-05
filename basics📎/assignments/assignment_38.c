#include <stdio.h>
#define MACRO(num,pos,n) (num) = ((num) & ((1 << n)-1)<<(pos-n+1))>>(pos-n+1)
int main()
{
  unsigned int num;
  int pos;
  int n;

  printf("Enter the number : ");
  scanf("%d",&num);
  printf("Enter the number of bits :");
  scanf("%d",&n);
  printf("Enter the position : ");
  scanf("%d",&pos);

  MACRO(num,pos,n);

  printf("Result : %u\n",num);

}
