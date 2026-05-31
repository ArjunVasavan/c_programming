#include <stdio.h>
int main()
{
   printf("Enter the n value : ");
  int n;
  scanf("%d",&n);

  int arr[n

  for ( int i = 0 ; i < n ; i++ )
  {
    scanf("%d",&arr[i]);
  }

  printf("Your Entered Numbers are : ");

  for (int i = 0 ; i < n ; i++ ) 
  {
    printf("%d ", arr[i]);
  }
}

