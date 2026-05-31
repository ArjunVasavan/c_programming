#include <stdio.h>

void read ( int row , int column , int arr[row][column])
{

  printf("Enter the Elements : ");
  for ( int i = 0 ; i < row ; i++ )
  {
    for ( int j = 0 ; j < column ; j++ )
    {
      scanf("%d",&arr[i][j]);
    }
  }
}

void write ( int row , int column , int arr[row][column])
{
  printf("Output =>>  \n");
  for ( int i = 0 ; i < row ; i++ )
  {
    for ( int j = 0 ;j < column ; j++ )
    {
      printf("%d ",arr[i][j]);
    }

    printf("\n");
  }
}

int main()
{

  int row;
  int column;
  printf("Enter the row : ");
  scanf("%d",&row);
  printf("Enter the column : ");
  scanf("%d",&column);

  int arr[row][column];
  read(row,column,arr);
  write(row,column,arr);
    
}
