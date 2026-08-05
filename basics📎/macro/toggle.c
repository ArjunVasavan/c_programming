#include<stdio.h>

#define TOGGLE(num,n) ((num) = ( (num) ^ ( 1 << (n) ) ) )

int main()
{

  printf("Enter the number : ");
  int num;
  scanf("%d",&num);

  int n;

  printf("Enter The 'n' Value : ");
  scanf("%d",&n);

  TOGGLE(num,n);


  printf("RESULT : %d \n",num);

}
