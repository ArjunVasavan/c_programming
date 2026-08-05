#include <stdio.h>

char* fun( char str[] )
{
    int i = 0;

    while ( str[i] )
    {
        if ((i == 0) || ( (str[i] != ' ') && (str[i+1] == ' ' || str[i+1] == '\0' )) || ((str[i-1] == ' ' && str[i] !=' ')) )
        {
            /* here loop is done and that loop is shifting */ 

            int k = i;
            
            while ( str[k] )
            {
                str[k] = str[k+1];
                k+=1;
            }
            str[k] = '\0';

        }

        i+=1;
    }

    return str;

}

int main()
{
    char str[100];
    printf("Enter the string : ");
    scanf("%[^\n]",str);
    
    printf("%s",fun(str));
}

