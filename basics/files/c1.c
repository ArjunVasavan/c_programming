#include<stdio.h>
#include <strings.h>

struct info
{
  int id;
  char name[10];
  char email[20];
  char add[30];
};
int main()
{
  FILE* fptr = fopen("abc.txt","w");

  int n;

  printf("Enter the number of people : ");
  scanf("%d",&n);

  struct info var[n];

  for ( int i = 0 ; i < n ; i++ )
  {
    printf("Enter the id : ");
    scanf("%d",&var[i].id);
    fprintf(fptr,"%d\t",var[i].id);
    getchar();
    printf("Enter the name : ");
    scanf("%[^\n]",var[i].name);
    fprintf(fptr,"%s\t",var[i].name);
    getchar();
    printf("Enter the email : ");
    scanf("%[^\n]",var[i].email);
    fprintf(fptr,"%s\t",var[i].email);
    getchar();
    printf("Enter the address : ");
    scanf("%s",var[i].add);
    fprintf(fptr,"%s\n",var[i].add);
  }

  fclose(fptr);



}
