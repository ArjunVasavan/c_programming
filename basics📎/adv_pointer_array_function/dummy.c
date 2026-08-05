#include <stdlib.h>
#include <stdio.h>

void magic(int** arr,int size)
{
  int val = 1;
  int row = 0;
  int col = size/2;
  int prev_row = row;
  int prev_col = col;

  while ( val <= size * size )
  {
    if (row < 0 )
    {
      row = size-1;
    }
    if (col >= size )
    {
      col = 0;
    }
    if ( arr[row][col] == 0 )
    {
      arr[row][col] = val;
      val+=1;
      prev_col = col;
      prev_row = row;
      col+=1;
      row-=1;
    }
    else 
    {
     row = prev_row+1;
     col = prev_col;
    }
  }
}

int main()
{
   int size;
   printf("Enter the size : ");
   scanf("%d",&size);

   int**arr = calloc(size,sizeof(int*));
   
   for ( int i = 0 ; i < size ; i++ )
  {
    arr[i] = calloc(size,sizeof(int));
  }

  magic(arr,size);
  for  ( int i = 0 ; i < size ; i++ )
  {
    for ( int j = 0 ; j < size ; j++ )
    {
      printf("%-3d ",arr[i][j]);  
    }
    printf("\n");
  }
} 
