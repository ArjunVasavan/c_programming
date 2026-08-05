#include<stdio.h>
void scan_arr(int row,int column,int arr[row][column])
{
  printf("Enter the elements : \n");
  for ( int i = 0 ; i < row ; i++ )
  {
    for ( int j = 0 ; j < column ; j++ )
    {
      scanf("%d",&arr[i][j]);
    }
  }
  printf("\n");
}
void print_arr(int row,int column,int arr[row][column])
{
  for ( int i = 0 ; i < row ; i++ )
  {
    for ( int j = 0 ; j < column ; j++ )
    {
      printf("%d ",arr[i][j]);
    }
    printf("\n");
  }

}

void columnsum(int row , int column, int arr[row][column] )
{
  int sum = 0;
  for ( int j = 0 ; j < column ; j++ )
  {
    sum = 0;
    int i = 0;
    for ( i = 0 ; i  < row ; i++ )
    {
      sum+=arr[i][j];
    }

    printf("\n");

    printf("column : %d Sum is =>> %d \n",j,sum);

  }
}

int main()
{
  int row,column;
  printf("Enter the row : ");
  scanf("%d",&row);
  printf("Enter the column : ");
  scanf("%d",&column);

  int arr[row][column];

  scan_arr(row,column,arr);

  print_arr(row,column,arr);

  columnsum(row,column,arr);
}
