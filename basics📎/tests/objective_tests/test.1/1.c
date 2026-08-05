#include <stdio.h>
void main()
{
  int j = 10, k = 20, l = 0;

  if ( j && k && l );
  {
    printf("All are non zero");
  }

  if (j)
  {
    printf("1");

    if ( !!k )
    {
      printf("2");
    }
  }
}
