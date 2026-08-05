#include <stdlib.h>
#include<stdio.h>
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

  for ( int i = 0 ; i < n ; i++ )
  {
    printf("%s ",arr[i]);
  }

}
