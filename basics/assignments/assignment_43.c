#include <stdlib.h>
#include <stdio.h>
int main()
{
  int number_of_elements;

  printf("Enter the number of Elements : ");
  scanf("%d",&number_of_elements);

  int* dynamic_pointer = malloc(sizeof(int)*number_of_elements);

  int mean = 0;
  printf("Enter the %d elements : \n",number_of_elements);
  for ( int i = 0 ; i < number_of_elements ; i++ )
  {
    printf("[%d]=>> ",i);
    scanf("%d",&dynamic_pointer[i]);
    mean+= dynamic_pointer[i];
  }

  mean/=number_of_elements;

  double variance = 0; // for storing variance
  for ( int i = 0 ; i < number_of_elements ; i++ )
  {
    dynamic_pointer[i] = dynamic_pointer[i] - mean;
    dynamic_pointer[i] = dynamic_pointer[i] * dynamic_pointer[i];
    variance+=dynamic_pointer[i];
  }
  variance/=number_of_elements;
  printf("VARIANCE =>> %lf \n",variance);

}
