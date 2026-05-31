#include <stdio.h>
#define GET(num,n) (num) = ((num) & (((1<<n)-1)))
int main()
{

  printf("Enter the number : ");
  int num;
  scanf("%d",&num);

  int n;
  printf("Enter the n value : ");
  scanf("%d",&n);

  GET(num,n);

  printf("OUTPUT : %d\n",num);
    
}
