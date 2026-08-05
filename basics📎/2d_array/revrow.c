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

  printf("\n");


}

// void reverse(int row, int column,int arr[row][column])
// {
//   for ( int i = 0 ; i < row ; i++ )
//   {
//     for ( int j = column-1 ; j >= 0 ; j-- )
//     {
//       printf("%d ",arr[i][j]);
//     }
//     printf("\n");
//   }
//
// }

void reverse ( int * arr , int size )
{
  for ( int i = 0 ; i < ( size/2 ) ; i++ )
  {
    int temp = arr[i];

    arr[i] = arr[size - i - 1];

    arr[size - i - 1] = temp;
  }
}

void reverse2d( int row , int column , int arr[row][column] )
{
  for ( int i = 0 ; i < row ; i++ )
  {
    reverse(arr[i],column);
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

  reverse2d(row,column,arr);

  printf("\n");
  print_arr(row,column,arr);
}
