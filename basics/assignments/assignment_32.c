#include <stdio.h>

#define UPDATE(num,n,m) (num) = ((((num) & (1 << n)) != 0 ) ? ((num) & (~(1<<m))) : (num))
int main()
{

  printf("Enter the number : ");
  int num;
  scanf("%d",&num);

  int n;
  printf("Enter the n value : ");
  scanf("%d",&n);

  int m;
  printf("Enter the m value : ");
  scanf("%d",&m);
  
  UPDATE(num,n,m);

  printf("RESULT : %d\n",num);
    
}
