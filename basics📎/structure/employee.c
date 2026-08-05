#include <stdio.h>
#include <string.h>
struct sinfo
{
    int id;
    char name[20];
    float sal;
    char email[100];
};

int main()
{
    struct sinfo var;

    printf("Enter the employee id : ");
    scanf("%d",&var.id);
    printf("Enter the name : ");
    scanf(" %s",var.name);
    printf("Enter the salary : ");
    scanf("%f",&var.sal);
    printf("Enter the email address : ");
    scanf(" %[^\n]",var.email);

    printf("id is %d \n",var.id);
    printf("name is %s\n",var.name);
    printf("email address is %s \n",var.email);
    printf("salary is %f \n",var.sal);
}

