#include<stdio.h>
int main()
{
  FILE* fptr = fopen("abc.txt","r");

  int i = 0;

  char ch;
  printf("Position of 'c' is at -> ");
  while ((ch = getc(fptr)) != EOF)
  {
    if ( ch == 'c')
    {
      printf("%d ",i);
    }

    i+=1;
  }

  printf("\n");

}
