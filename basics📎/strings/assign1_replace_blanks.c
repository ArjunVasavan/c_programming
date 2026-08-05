#include <stdio.h>

char* blank(char* str)
{
    int i = 0;

    while ( str[i] )
    {

        if( str[i] == ' ' && str[i+1] == ' ' )
        {
            int j = i;

            while ( str[j] )
            {
        str[j] = str[j+1];
                j+=1;
            }

            str[j] = '\0';


        }

        else
        {
            i+=1;
        }
    }

    return str;
}

int main()
{
    char str[50];
    printf("Enter the string -> ");

    scanf("%[^\n]",str);

    printf("The modified string is -> %s \n",blank(str));


}

