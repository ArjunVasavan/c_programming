#include<stdio.h>
#include <stdlib.h>
int main()
{
  printf("Enter the size you wanna store : ");
  int n;
  scanf("%d",&n);

  printf("Enter the elements ->> ");
  int* ptr = calloc(n,sizeof(int));
  for ( int i = 0 ;i < n ; i++ )
  {
    scanf("%d",&ptr[i]);
  }

  printf("Stored Elements are =>> ");
  for ( int i = 0 ;i < n ; i++ )
  {
    printf("%d ",ptr[i]);
  }
  printf("\n");

}
