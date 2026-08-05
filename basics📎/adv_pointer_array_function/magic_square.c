/*
--------------------------------------------------------------------------------

Name : Arjun Vasavan

Date : 23-10-2025

Description : Program to generate a n*n magic square

Test Case 1:

Enter a number: 3

8      1      6
3      5      7
4      9      2

Test Case 2:

Enter a number: -6

Error : Please enter only positive values



--------------------------------------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>
void magic_square( int** , int );

int main()
{
  int size;

  printf("Enter a number : ");
  scanf("%d",&size);

  if ( (size & 1) == 0 )
  {
    // the reason is we cannot put middle number one if its even
    printf("Error! Please enter odd numbers only.\n");
    return 1;
  }
  else if( size < 0)
  {
    printf("Please enter only positive values\n");
    return 1;
  }

  // were creating both dynamic so that all values inside it will be zero
  // as its  an in** it is an pointer which stored address of array of pointers
  int** arr = calloc(size,sizeof(int*));


  for ( int i = 0 ; i < size ; i++ )
  {
    // were creating column side as calloc here
    arr[i] = calloc(size,sizeof(int));
  }

  magic_square(arr,size); // passing to function for magic square

  // printing part
  for ( int i = 0 ; i < size ; i++)
  {
    for ( int j = 0 ; j < size ; j++)
    {
      printf("%-3d  ",arr[i][j]);
    }
    printf("\n");
  }

  // freeing part to prevent memory leakage
  for ( int i = 0 ; i < size ; i++ )
  {
      free(arr[i]); // freeing each columns first
  }

  free(arr); // freeing the main array

}

void magic_square(int** arr,int size )
{
  int row = 0;
  int col = (size)/2;
  int val = 1;
  // at the beginning 1 should be assigned at the middle of first row
  int prev_row = row; // storing row as backup
  int prev_col = col; // storing column as backup;

  while( val <= size*size ) // looping till we reach size*size times
  {
    if ( row < 0 ) // if row reached top then go to the bottom
    {
      row = size-1; // row is assigned to bottom size
    }
    if ( col >= size ) // if column reached end then go to starting which is 0th
    {
      col = 0; // assigning 0th 
    }

    if ( arr[row][col] == 0 ) // checking if already occupied or not
    {
      arr[row][col] = val; // if not occupied assigning the value
      val+=1; // value is increamented
      prev_row = row; // row backup
      prev_col = col; // column backup
      row-=1; // row moves to top
      col+=1; // column moves to right side
    }
    else  // if its already occupied
    {
      row = prev_row + 1; // row go to the previous place and go to bottom of it
      col = prev_col; // column go to the previous place only.
    }
  }
}


