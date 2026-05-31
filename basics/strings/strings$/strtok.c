#include<stdio.h>

char* fun(char* str, char* del)
{
  static char* ptr;

  static int i = 0 ;
  int start;

  if ( str != NULL )
  {
    ptr = str;
    i = 0 ;
  }

  start = i;

  while( ptr[i] )
  {
    int j = 0;

    while ( del[j])
    {
      if ( ptr[i] == del[j] )
      {
        ptr[i] = '\0';
        i+=1;
        

        if ( ptr[start] != '\0')
        {
        return ptr+start;
        }
        else {
        
          start = i--;
        }

      }
        j+=1;

    }
    
    i+=1;
  }

  if ( ptr[start] != '\0' )
  {
    return ptr+start;
  }
  else {
  
    return NULL;
  }
}

int main()
{
  char str[50],del[50];
  printf("Enter an Character  :");
  scanf("%[^\n]",str);
  printf("Enter an Delimeter  : ");
  scanf(" %[^\n]",del);

  char* token = fun(str,del);


  while ( token != NULL )
  {

    printf("Token : %s \n",token);
    token = fun(NULL,del);
  }


}
