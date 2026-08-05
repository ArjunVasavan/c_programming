#include <stdio.h>
#include <stdlib.h>
int main()
{
  int row,col;

  printf("Enter the number of rows and cols : ");
  scanf("%d %d",&row,&col);

  int**arr = malloc(row*sizeof(int*));

  for ( int i = 0 ; i < row ; i++ )
  {
    arr[i] = malloc(col*sizeof(int));
  }

  printf("Enter the elements : ");
  for ( int i = 0 ; i < row ; i++ )
  {
    for ( int j = 0 ; j < col ; j++ )
    {
      scanf("%d",&arr[i][j]);
    }
  }

  printf("Elements of teh array are : \n");
  for ( int i = 0 ; i < row ; i++ )
  {
    for ( int j = 0 ; j < col ; j++ )
    {
      printf("%d ",arr[i][j]);
    }
    printf("\n");
  }

  free(arr);
}
