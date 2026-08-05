#include<stdio.h>

#define TOGGLE(num,n,pos) ((num) = ( (num) ^ (( 1 << (n)) - 1)  ) << ( pos - n + 1) )

int main()
{

  printf("Enter the number : ");
  int num;
  scanf("%d",&num);

  int n;

  printf("Enter The 'n' Value : ");
  scanf("%d",&n);

  printf("Enter the Position : ");
  int pos;
  scanf("%d",&pos);

  TOGGLE(num,n,pos);


  printf("RESULT : %d \n",num);

}
