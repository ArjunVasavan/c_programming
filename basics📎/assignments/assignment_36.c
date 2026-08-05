#include <stdio.h>
#define LEFT(num,n) (num) = (((num) << (n)) | ((num) >> (32 - (n))))
int main()
{
    int num;
  printf("Enter the Number : ");
  scanf("%d",&num);

  int n;
  printf("Enter the n : ");
  scanf("%d",&n);

  LEFT(num,n);
  printf("Output = %d \n",num);
}
 
