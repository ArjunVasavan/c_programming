#include <stdio.h>

void ap(int first , int ratio , int limit)
{
  printf("Ap : ");
  for ( int i = 1 ; i < limit ; i++ )
  {
    printf("%d ",first);
    first+=ratio;
  }
  printf("\n");
}

void gp(int first , int ratio , int limit)
{
  printf("GP : ");
  for ( int i = 1 ; i < limit ; i++ )
  {
    printf("%d ",first);
    first*=ratio;
  }

  printf("\n");

}

void hp(int first , int ratio , int limit)
{
  for ( int i = 1 ; i < limit ; i++ )
  {
    printf("%g ",(float)1/first);
    first+=ratio;
  }

}
int main()
{
  printf("Enter the first number : ");
  int first;
  scanf("%d",&first);
  printf("Enter the common ratio : ");
  int ratio;
  scanf("%d",&ratio);
  int limit;
  printf("Enter the limit : ");
  scanf("%d",&limit);

  ap(first,ratio,limit);
  gp(first,ratio,limit);
  hp(first,ratio,limit);

}

