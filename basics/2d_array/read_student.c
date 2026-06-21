#include <stdio.h>
#include <stdlib.h>
int main()
{
  printf("Enter the number of students : ");
  int n;
  scanf("%d",&n);

  char* students[n];

  for ( int i = 0 ; i < n ; i++ )
  {
    students[i] = malloc(n*sizeof(char));
  }

  printf("Enter the students Name : ");

  for ( int i = 0 ; i < n ; i++ )
  {
    scanf("%s",students[i]);
  }

  printf("Students Name are : ");

  for ( int i = 0 ; i < n ; i++ )
  {
    printf("%s \n",students[i]);
  }
}
