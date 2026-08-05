#include <stdio.h>

void negfib(int limit,int first,int second,int next)
{
  if ( limit < 0 )
  {
    if ( limit == 0 )
    {
      printf("0\n");
    }
    if (first == 0 && second == 1 && next == 0 )
    {
      printf("0 1\n");
      next = first - second;
      first = second;
      second = next;
    }
    if ( next <= -limit && next >= limit) 
    {
      printf("%d ",next);
      next = first - second;
      first = second;
      second = next;
      negfib(limit,first,second,next);
    }


  }
  else 
  {
    printf("Invalid input \n");
  }
}

int main()
{
  int limit;
  printf("Enter the limit : ");
  scanf("%d",&limit);

  negfib(limit,0,1,0);

}
