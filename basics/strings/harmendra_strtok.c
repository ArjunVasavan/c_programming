#include <stdio.h>
#include <string.h>
#include <stdio_ext.h>

char *my_strtok(char str[], const char delim[])
{
    static char* ptr;
    static int i=0;
    
    if ( str != NULL )
    {
        ptr = str;
    }
    
    int start=i;
    
    while( ptr[i] != '\0' )
    {
        int j=0;
        while ( delim[j] != '\0' )
        {
            if ( ptr[i] == delim[j] )
            {
                ptr[i] ='\0';
                i++;
                
                // j=0;
                // while( delim[j] )
                // {
                //     if ( ptr[i] == delim[j] )
                //     {
                //         ptr[i] = '\0';
                //         i++;
                //     }
                //     j++;
                // }
                if ( ptr[start] != '\0')
                    return ptr+start;
                else
                {
                    start = i--;
                }
            }
            j++;
        }
        i++;
    }
    
    if (ptr[start] != '\0' )
    {
        return ptr+start;
    }
    else
    {
        return NULL;
    }
    
}

int main()
{
    char str[50], delim[50];
    
    printf("Enter the string  : ");
    scanf("%s", str);
    
    __fpurge(stdout);
 
    printf("Enter the delimeter : ");
    scanf("\n%s", delim);
    __fpurge(stdout);
    
    char *token = my_strtok(str, delim);
    printf("Tokens :\n");
    
    while (token)
    {
        printf("%s\n", token);
        token = my_strtok(NULL, delim);
    }
}
