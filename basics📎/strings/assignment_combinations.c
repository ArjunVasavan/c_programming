#include<stdio.h>

void swap ( char* str , int start , int end )
{
  char temp = str[start];
  str[start] = str[end];
  str[end] = temp;
}
int my_strlen(char str[])
{
  int i = 0 ; 
  while ( str[i] )
  {
    i+=1;
  }

  return  i;
}

void combination ( char* str , int start , int end )
{
  if ( start == end )
  {
    printf("%s ",str);
  }
  else 
{
    for ( int i = start ; i <= end ; i++ )
    {
      swap(str,i,start);
      combination(str,start+1,end);
      swap(str,i,start);
    }
  }
}
int main()
{
  char str[100];
  int n;
  int res;
  printf("Enter a string: ");
  scanf("%100[^\n]",str);    
  n = my_strlen(str);
  combination(str,0,n-1);                       
  return 0;
}
