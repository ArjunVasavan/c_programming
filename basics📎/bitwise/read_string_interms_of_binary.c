#include<stdio.h>
#include <string.h>
int main()
{
  char str[32];
  printf("Enter the binary String : ");
  scanf("%s",str);

  int len = strlen(str);

  char ascii = 0;

  int j = 0;
  for ( int i = len ; i >= 1 ; i-- )
  {

    if ( str[i - 1] == '1')
    {
      ascii = ascii | (1 << j);
      j+=1;
    }
    else
    {
      j+=1;
    }
  }

  if (( ascii >= 'a' && ascii <= 'z')|| (ascii >= 'A' && ascii <= 'Z'))
  {
    printf("%s is %c\n",str,ascii);
  }
  else 
  {
    printf("%s is %d\n",str,ascii);
  }
}
