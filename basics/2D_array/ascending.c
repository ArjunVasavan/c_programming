#include <string.h>
#include <stdlib.h>
#include<stdio.h>
#include <strings.h>
int main()
{
  printf("Enter the number of student : ");
  int n;
  scanf("%d",&n);

  char* arr[n];

  for ( int i = 0 ; i < n ; i++ )
  {
    arr[i] = malloc(20*sizeof(char));

  }

  for ( int i = 0 ; i < n ; i++ )
  {
    printf("Enter the name of student %d : ",i+1);
    scanf("%s",arr[i]);
  }


  for ( int i = 0 ; i < n - 1 ; i++ )
  {
    for ( int j = 0 ; j < n - i - 1 ; j++ )
    {
      if ( strcasecmp(arr[j],arr[j+1]) > 0 )
      {
        // char * temp = arr[j];  THIS WILL SWAP THE ARRAY IN STACK
        // arr[j] = arr[j+1];
        // arr[j+1] = temp;

        char temp[20]; // THIS WILL SWAP THE MALLOC ARRAYS IN HEAP
        strcpy(temp,arr[j]);
        strcpy(arr[j],arr[j+1]);
        strcpy(arr[j+1],temp);
      }
    }
  }

  for ( int i = 0 ; i < n ; i++ )
  {
    printf("%s ",arr[i]);
  }

}
