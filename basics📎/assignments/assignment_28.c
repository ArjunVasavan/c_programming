#include <stdio.h>

void squeeze ( char* str1, char* str2)
{
  int i = 0;

  while ( str1[i] != '\0' )
  {
    int j = 0;

    while ( str2[j] )
    {

      if ( str1[i] == str2[j] )
      {
        int k = i;

        while ( str1[k] )
        {

          str1[k] = str1[k+1];

          k+=1;
        }

        str1[k] = '\0';

        i-=1;

      }

      j+=1;
    }
    i+=1;
  }

}
int main()
{
  printf("Enter the string1 : ");
  char str1[50];
  scanf("%[^\n]",str1);

  printf("Enter the string2 :");
  char str2[50];
  getchar();
  scanf("%[^\n]",str2);

  squeeze(str1,str2);

  printf("Result : %s\n",str1);
}
