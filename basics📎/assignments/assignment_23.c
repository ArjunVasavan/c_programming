#include <stdio.h>

int myatoi(char * str )
{
  int i = 0;
  int number = 0;
  int itsneg = 0;

  if ( str[i] == '-' )
  {
    itsneg = 1;
    i+=1;
  }
  if(str[i] == '+') 
  {
    itsneg = 0;
    i+=1;
  }
  if ( (str[0] == '+' || str[0] == '-') && (str[0] =='+' || str[1] =='-') )
  {
    return 0;
  }
  while ( str[i] )
  {
    if ( (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z' ))
    {
      break;
    }
    number*=10;
    number += ( str[i] - 48);
    i+=1;
  }

  if (itsneg )
  {
    return -1*number;
  }

  return number;
}

int main()
{
   printf("Enter the number asa character : ") ;
  char str[20];
  scanf("%[^\n]",str);

  printf("Output of ATOI : %d \n",myatoi(str));
}
