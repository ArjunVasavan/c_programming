#include <stdio.h>
#include <string.h>

struct comp
{
    char name[20];
};
int main()
{

    struct comp n[5];

    char find[10];

    printf("Print characters to struct : ");

    for ( int i = 0 ; i < 5 ; i++ )
    {
        scanf("%s",n[i].name);
    }

    printf("Enter the character to find : ");

    scanf("%s",find);

    for ( int i = 0 ; i < 5 ; i++ )
    {
        if ( strcmp(n[i].name,find) == 0 )
        {
            printf("The value is founded and its on %dth position \n",i);
            return 0;
        }
    }
    printf("Its not found\n");

}

