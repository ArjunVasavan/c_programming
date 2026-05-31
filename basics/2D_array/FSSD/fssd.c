#include <stdio.h>
#include <stdlib.h>

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

void write ( int row , int column ,int** arr )
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

  int* arr[row];

  for ( int i = 0 ; i < row ; i++ )
  {
    arr[i] = malloc(column*sizeof(int));
  }

  read(row,column,arr);
  write(row,column,arr);

  printf("Enter the new Column : ");

  int ncolumn;

  scanf("%d",&ncolumn);
  for ( int i = 0 ; i < row ; i++ )
  {
    arr[i] = realloc(arr[i],ncolumn*sizeof(int));
  }

  printf("Enter the New Elements : ");
  if ( ncolumn > column )
  {
    for ( int i = 0 ; i < row ; i++ )
    {
      for ( int j = column ; j < ncolumn ; j++ )
      {
        scanf("%d ",&arr[i][j]);
      }
    }
  }
    
  write(row,column,arr);
}
