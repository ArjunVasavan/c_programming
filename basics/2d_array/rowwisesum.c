#include<stdio.h>
void scan_arr(int row,int column,int arr[row][column])
{
  printf("Enter the elements : ");
  for ( int i = 0 ; i < row ; i++ )
  {
    for ( int j = 0 ; j < column ; j++ )
    {
      scanf("%d",&arr[i][j]);
    }
  }
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

void rowsum(int row , int column, int arr[row][column] )
{
  int sum = 0;
  for ( int j = 0 ; j < row ; j++ )
  {
    sum = 0;
    int i = 0;
    for ( i = 0 ; i  < column ; i++ )
    {
      sum+=arr[j][i];
    }

    printf("\n");

    printf("Row : %d Sum is =>> %d \n",j,sum);

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

  rowsum(row,column,arr);
}
