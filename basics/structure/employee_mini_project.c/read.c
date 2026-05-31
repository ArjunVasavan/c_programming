#include <stdio.h>

struct employee
{
  int id;
  char name[15];
  char email[30];
  float salary;
};

void read(struct employee* str , int n )
{
    printf("Enter the employee details  -> \n");
    for ( int i = 0 ; i < n ; i++ )
    {
        printf("No.%d",i+1);
        printf("\n");
        printf("Enter employee ID : ");
        scanf("%d",&str[i].id);
        printf("Enter employee name : ");
        scanf("%s",str[i].name);
        printf("Enter employee email : ");
        scanf(" %[^\n]",str[i].email);
        printf("Enter employee salary : ");
        scanf("%f",&str[i].salary);
        printf("\n");
    }
}

void write(struct employee* str, int n)
{
    printf("-----------------------------\n");

    for ( int i = 0 ; i < n ; i++ )
    {
        printf("EMPLOYEE ID     : %d\n",str[i].id);
        printf("EMPLOYEE NAME   : %s\n",str[i].name);
        printf("EMPLOYEE EMAIL  : %s\n",str[i].email);
        printf("EMPLOYEE SALARY : %g\n",str[i].salary);
        printf("\n");
    }
}

int main()
{
    int n;
    printf("Enter the number of employees : ");
    scanf("%d",&n);
    
    struct employee str[n]; //declaring an var 
    read(str,n);
    write(str,n);
}

