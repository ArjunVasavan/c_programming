#include<stdio.h>
struct info 
{
  int id;
  char name[10];
  char email[20];

};
int main()
{
  FILE* fptr = fopen("runner.txt","w+");

  int n;

  printf("Enter the number of peoples : ");
  scanf("%d",&n);
  struct info people[n];

  for ( int i = 0 ; i < n ; i++ )
  {
    printf("Enter the name : ");
    scanf("%s",people[i].name);
    printf("Enter the id : ");
    scanf("%d",&people[i].id);
    printf("Enter the email : ");
    scanf("%s",people[i].email);

  }

#include<stdio.h>
struct info 
{
  int id;
  char name[10];
  char email[20];

};
int main()
{
  FILE* fptr = fopen("runner.txt","w+");

  int n;

  printf("Enter the number of peoples : ");
  scanf("%d",&n);
  struct info people[n];

  for ( int i = 0 ; i < n ; i++ )
  {
    printf("Enter the name : ");
    scanf("%s",people[i].name);
    printf("Enter the id : ");
    scanf("%d",&people[i].id);
    printf("Enter the email : ");
    scanf("%s",people[i].email);

  }

  for ( int i = 0 ; i < n ; i ++ )
  {
    fprintf(fptr,"ID = %d \n Name = %s \n Email = %s\n",people[i].id,people[i].name,people[i].email);
  }

  int ch;
  rewind(fptr);
  while( (ch = getc(fptr)) != EOF )
  {
      putchar(ch);
  }

  fclose(fptr);


}
  for ( int i = 0 ; i < n ; i ++ )
  {
    fprintf(fptr,"ID = %d \n Name = %s \n Email = %s\n",people[i].id,people[i].name,people[i].email);
  }

  int ch;
  rewind(fptr);
  while( (ch = getc(fptr)) != EOF )
  {
      putchar(ch);
  }

  fclose(fptr);


}
