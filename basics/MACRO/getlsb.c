#include<stdio.h>

#define GET(num,n) ((num) = ( (num) & ( (1 << n) - 1 ) ) )

int main()
{

  printf("Enter the number : ");
  int num;
  scanf("%d",&num);

  int n;

  printf("Enter The 'n' Value : ");
  scanf("%d",&n);

  GET(num,n);


  printf("RESULT : %d \n",num);

}

#include <stdio.h>

int print_bits(int, int);

int main()
{
    int num, n;
    
    printf("Enter num, n :\n");
    scanf("%d%d", &num, &n);
    
    printf("Binary form of %d:", num);
    print_bits(num, n);
 }

int print_bits(int num  , int n)
{
  num = ( (num) & ( (1 << n) - 1 ) );

  for ( int i = 31 ; i >= 0 ; i-- )
  {
    if (( num &(1 << i)) == 0)
    {
      printf("0");
    }
  else 
  {
      printf("1");
  }

  }
  printf("\n");

}
