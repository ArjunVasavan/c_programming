#include <locale.h>
#include <stdio.h>
void fun(int *arr1, int size, int *arr2, int *new_size);
int main()
{
  printf("Enter the size of the array : ");

  int size;
  scanf("%d",&size);

  int arr1[size];
  int arr2[size];
  printf("Enter the elements of the array : ");

  for ( int i = 0 ; i < size ; i++ )
  {
    scanf("%d",&arr1[i]);
  }

  int new_size;
  fun(arr1,size,arr2,&new_size);


  printf("Result : ");
  for ( int i = 0 ; i < new_size ; i++ )
  {
    printf("%d ",arr2[i]);
  }
  
}

void fun(int *arr1, int size, int *arr2, int *new_size)
{


  int dup_found = 0;
  *new_size = 0;

  for ( int i = 0 ; i < size ; i++ )
  {

    dup_found = 0;

    for ( int j = i+1 ; j < size ; j++ )
    {
      if ( arr1[i] == arr1[j] )
      {
        dup_found = 1;
        break;
      }
    }

    if ( !dup_found )
    {
      arr2[*new_size] = arr1[i];
      (*new_size)+=1;
    }
  }
}
