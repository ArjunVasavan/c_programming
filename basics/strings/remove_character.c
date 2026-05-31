#include <stdio.h>

char* charfind(char* str,char ch)
{
    int i = 0;

    while(str[i])
    {
        if ( str[i] == ch )
        {
            int j = i;
            while(str[j])
            {
                str[j] = str[j+1];

                j++;
            }
        }
        else
        {
            i++;
        }
    }

    return str;
}

int main()
{
    char str[50];
    printf("Enter the Strign-> ");
    scanf("%[^\n]",str);

    char ch;

    printf("Enter the Character you want to remove -> ");
    scanf(" %c",&ch);

    char* ret = charfind(str,ch);

    printf("Result -> %s\n",ret);
}

