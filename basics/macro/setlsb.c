#include<stdio.h>

#define SET(num,n) ((num) = ( (num) | ( 1 << (n) )-1 ) )

int main()
{

  printf("Enter the number : ");
  int num;
  scanf("%d",&num);

  int n;

  printf("Enter The 'n' Value : ");
  scanf("%d",&n);

  SET(num,n);


  printf("RESULT : %d \n",num);

}
