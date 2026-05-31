#include<stdio.h>
int main()
{
  FILE* fptr = fopen("abc.txt","r");

  int i = 0;

  char ch;
  while ((ch = getc(fptr)) != EOF)
  {
    i+=1;
  }

  printf("Size of file is %d\n",i);
}
