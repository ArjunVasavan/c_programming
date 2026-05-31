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
    struct sinfo var1 = {123,"Arjun","Kerala"};

    struct sinfo var2;

    var2.id = 288;

    strcpy(var2.name,"Abhi");

    strcpy(var2.add,"Banglore");

    printf("id is %d \n",var1.id);
    printf("name is %s\n",var1.name);
    printf("address is %s \n",var1.add);
}

