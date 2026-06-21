#include<stdio.h>

#include <string.h>

struct employee 
{
  int id;
  char name[20];
  char email[30];
};
int main()
{

  FILE* fptr;
  printf("===Employee Menu===\n");
  int n;
  printf("Enter the of employees you need to add: ");
  scanf("%d",&n);
  struct employee emp[n];
  fptr = fopen("employee_record.txt","w");

  for ( int i = 0 ; i <  n ; i++ )
  {
    printf("Enter the name : ");
    scanf("%s",emp[i].name);
    printf("Enter the id : ");
    scanf("%d",&emp[i].id);
    printf("Enter the email : ");
    scanf("%s",emp[i].email);

    fprintf(fptr,"%s %d %s\n",emp[i].name,emp[i].id,emp[i].email);
  }

  fclose(fptr);

  printf("===Employee Menu===\n");
  printf("1.search employee \n");
  printf("2.search by id \n");
  printf("3.search by email \n");
  printf("coode any option : ");
  int option;
  int isearch;
  scanf("%d",&option);
  char search[30];
  if ( option == 1 || option == 3 )
  {
    printf("Enter what to search : ");
    scanf("%s",search);

  }
  else {
    printf("Enter what to search : ");
    scanf("%d",&isearch);
  }

  FILE*  wptr = fopen("employee_record.txt","r");

  struct employee temp;
  switch ( option )
  {
    case 1 : 
      {
        int i = 0;
        while ( fscanf(wptr,"%s %d %s",temp.name,&temp.id,temp.email) == 3 )
        {
          if (strcmp(temp.name,search) == 0 )
          {
            printf("name : %s \n",temp.name);
            printf("id : %d \n",temp.id);
            printf("email : %s\n",temp.email);
            printf("\n");
          }

          i+=1;
        }
      }
      break;
    case 2 : 
      {
        int i = 0;
        while ( fscanf(wptr,"%s %d %s",temp.name,&temp.id,temp.email) == 3 )
        {
          if ( temp.id == isearch )
          {
            printf("name : %s \n",temp.name);
            printf("id : %d \n",temp.id);
            printf("email : %s\n",temp.email);
            printf("\n");
          }

          i+=1;
        }
      }
      break;
    case 3 : 
      {
        int i = 0;
        while ( fscanf(wptr,"%s %d %s",temp.name,&temp.id,temp.email) == 3 )
        {
          if (strcmp(temp.email,search) == 0 )
          {
            printf("name : %s \n",temp.name);
            printf("id : %d \n",temp.id);
            printf("email : %s\n",temp.email);
            printf("\n");
          }

          
        }
      }
      break;
  }

  fclose(wptr);

}
