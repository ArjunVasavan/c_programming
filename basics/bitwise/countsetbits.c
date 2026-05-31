#include<stdio.h>
int main()
{
  printf("Enter the number is Hexadecimal format: ");
  int hex;
  scanf("%X",&hex);
  int count = 0;

  for ( int i = 0 ; i < 32 ; i++ )
  {
    if (( hex & ( 1 << i)) != 0 )
    {
      count+=1;
    }
  }

  printf("Number of set bit is: %d",count);
}
