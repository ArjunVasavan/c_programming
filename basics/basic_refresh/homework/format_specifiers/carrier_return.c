#include<stdio.h>
#include<stdio_ext.h>
int main()
{
  for ( int i = 1 ; i <= 100 ; i++ )
  {
    for ( int j = 1 ; j <= 100 ; j++ )
    {
      if ( j <= i )
      {
        printf("-");
      }
         else {
         printf(" ");
         }
      int count = 0;

      while ( count <=  100000 )
      {
        count+=1;
      }
      if ( j == 100 )
      {
        printf("\r");
      }
      if ( i < 100 )
      {
        __fpurge(stdout);
      }
    }
  }
}
