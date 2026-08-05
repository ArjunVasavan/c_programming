#include <stdio.h>

void myitoa(int n ,char* str)
{
  int rev = 0;

  while ( n != 0 )
  {
    int rem = n % 10;
    rev*=10;
    rev+=rem;
    n /= 10;
  }
  int i = 0;

while ( rev != 0 )
  {
    int rem = rev % 10;
    str[i] = rem + 48;
    rev/=10;
    i+=1;
  }
}

int main()
{
   printf("Enter the integer : ");
  int n;
  scanf("%d",&n);

  char str[50];
  myitoa(n,str);
  printf("OUTPUT of itoa : %s \n",str);
}
