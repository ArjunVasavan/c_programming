#include <stdio.h>

void printsort(int* arr,int size)
{
  int smallest = arr[0];
  int largest = arr[0];

  for ( int i = 0 ; i < size ; i++ )
  {
    if ( smallest > arr[i] )
    {
      smallest = arr[i];
    }
    if ( largest < arr[i] )
    {
      largest = arr[i];
    }
  }

  int temp = largest;

  for ( int i = 0 ; i < size ; i++ )
  {
    printf("%d ",smallest);

    for(int i = 0 ; i < size ; i++ )
    {
      if (  arr[i] > smallest &&  arr[i] < largest )
      {
        largest = arr[i];
      }
    }



    smallest = largest;

    largest = temp;

  }

}
int main()
{
   printf("Enter the size of the array : ");
  int size;
  scanf("%d",&size);
  int arr[size];

  printf("Enter the elements : ");

  for ( int i = 0 ; i < size ; i++ )
  {
    scanf("%d",&arr[i]);
  }
  printsort(arr,size);
}
