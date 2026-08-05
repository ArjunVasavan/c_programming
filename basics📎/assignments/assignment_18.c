#include <stdio.h>

int fact(int n,int out)
{
  if (  n > 0 )
  {
    out*=n;
    n-=1;
    fact(n,out);
  }
  else if ( n == 0)
  {
    return out;
  }

}

int main()
{
   int n;
  printf("Enter an Number : ");
  scanf("%d",&n);

  printf("Factorail : %d \n",fact(n,1));
}
