#include <stdlib.h>
#include <stdio.h>

// here were using array of pointer actually 
void read ( int row , int column , int** arr ) 
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

void write ( int row , int column , int** arr )
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

  int** arr = malloc(row*sizeof(int*));

  for ( int i = 0 ; i < row ; i++ )
  {
    arr[i] = malloc(column*sizeof(int));
  }

  read(row,column,arr);
  write(row,column,arr);

  printf("Enter the New Row ");
  int nrow;
  scanf("%d",&nrow);

  if ( nrow < row )
  {
    for ( int i = nrow ; i < row ; i++ )
    {
      free(arr[i]);
    }
  }

  arr = realloc(arr,nrow * sizeof(int*));

  if ( nrow > row )
  {
    for ( int i = row ; i < nrow ; i++ )
    {
      arr[i] = malloc(column*sizeof(int));
    }

    printf("Enter The Extra Elements : ");

    for ( int i = row ; i < nrow ; i++ )
    {
      for ( int j = 0 ; j < column ; j++ )
      {

        scanf("%d",&arr[i][j]);
      }
    }
  write(nrow,column,arr);
  }

}
