#include<stdio.h>
int main()
{
  int row,column;
  printf("Enter the row : ");
  scanf("%d",&row);
  printf("Enter the column : ");
  scanf("%d",&column);

  int arr[row][column];

  printf("Enter the elements : ");
  for ( int i = 0 ; i < row ; i++ )
  {
    for ( int j = 0 ; j < column ; j++ )
    {
      scanf("%d",&arr[i][j]);
    }
  }
  for ( int i = 0 ; i < column ; i++ )
  {
    for ( int j = 0 ; j < row ; j++ )
    {
      printf("%d ",arr[j][i]);
    }
    printf("\n");
  }
}
