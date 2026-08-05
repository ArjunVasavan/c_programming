#include <stdio.h>
#include <string.h>
struct sinfo
{
    int id;
    char name[20];
    char add[60];
};

int main()
{
    struct sinfo var = {123,"Arjun","Kerala"};

    printf("Enter the id : ");
    scanf("%d",&var.id);
    printf("Enter the name : ");
    scanf(" %s",var.name);
    printf("Enter the address : ");
    scanf(" %[^\n]",var.add);

    printf("id is %d \n",var.id);
    printf("name is %s\n",var.name);
    printf("address is %s \n",var.add);
}

