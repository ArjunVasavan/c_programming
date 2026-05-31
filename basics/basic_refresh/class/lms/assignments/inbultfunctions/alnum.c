#include <stdio.h>
#include <ctype.h>
int main()
{
    char ch;
    printf("Enter an Character : ");
    scanf("%c",&ch);

    if (isalnum(ch))
    {
        printf("isalnum(%c) --> %d\n",ch,isalnum(ch));
        printf("Its an Alpha numberic \n");
    }
    else
    {
        printf("isalnum(%c) --> %d\n",ch,isalnum(ch));
        printf("Its not an Alpha numeric \n");
    }
    
}

