#include <stdio.h>

#define MACRO(num,val,n) (num) = (((num)&(~((1<<n)-1))) | ((val) & (((1<<n)-1))))
int main()
{
  printf("Enter the num : ");
  int num;
  scanf("%d",&num);

  int n;
  printf("Enter the n value : ");
  scanf("%d",&n);

  int val;
  printf("Enter the val : ");
  scanf("%d",&val);

  MACRO(num,val,n);

  printf("Result : %d\n",num);
}
