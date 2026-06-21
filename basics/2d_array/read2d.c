#include <stdio.h>

void scan(int row,int col,int arr[row][col])
{

  printf("Enter the elements : ");

  for (int i = 0 ; i < row ; i++ )
  {
    for ( int j = 0 ; j < col ; j++ )
    {
      scanf("%d",&arr[i][j]);
    }
  }

}
void print(int row,int col,int arr[row][col])
{
  printf("Elements of the array are: ");

  for (int i = 0 ; i < row ; i++ )
  {
    for ( int j = 0 ; j < col ; j++ )
    {
      printf("%d ",arr[i][j]);
    }
    printf("\n");
  }


}
int main()
{
  printf("Enter the number of rows and cols : ");
  int row,col;
  scanf("%d %d",&row,&col);

  int arr[row][col];

  scan(row,col,arr);
  print(row,col,arr);
}
