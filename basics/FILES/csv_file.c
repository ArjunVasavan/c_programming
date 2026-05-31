#include<stdio.h>

typedef struct 
{
  char name[20];
  char number[15];
  char email[15];
}contacts;
int main()
{
  contacts var;

  FILE* fp = fopen("contactbook.csv", "a+");

  printf("Enter the name : ");
  fgets(var.name , sizeof(var.name),stdin);

  int i = 0;
  while ( var.name[i] ) 
  {
    if ( var.name[i] == '\n')
    {
      var.name[i] = '\0';
    }
    i+=1;
    printf("Enter the email : ");
    fgets(var.email , sizeof(var.email),stdin);

    i = 0;
    while ( var.email[i] ) 
    {
      if ( var.email[i] == '\n')
      {
        var.email[i] = '\0';
      }
      i+=1;
    }
    printf("Enter the number : ");
    fgets(var.number , sizeof(var.number),stdin);

    i = 0;
    while ( var.number[i] ) 
    {
      if ( var.number[i] == '\n')
      {
        var.number[i] = '\0';
      }
      i+=1;
    }


    fprintf(fp," %s,%s,%s\n",var.name,var.number,var.email);

    printf("Successfully stored ");

    char line[100];

    while (fgets(line,sizeof(line),fp))
    {
      int i = 0;

      while (line[i])
      {
        if ( line[i] == '\n' )
        {
          line[i] = '\0';
          break;
        }

        i+=1;

      }

      printf("%s",line);
    }

    fclose(fp);
  }
}
