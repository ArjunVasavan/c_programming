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

void transpose(int row, int column, int arr[row][column] )
{
  for ( int i = 0 ; i < column ; i++ )
  {
    for ( int j = row - 1 ; j >= 0 ; j-- )
    {
      printf("%d ",arr[j][i]); // or i can just make an normal print loop where another matrix call trans[j][i] = mat[i][j];
    }
    printf("\n");
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

  // print_arr(row,column,arr);

  printf("\n");

  transpose(row,column,arr);
}
