#include <stdio.h>
#include <string.h>
#include <stdio_ext.h>
char *my_strtok(char str[], const char delim[])
{
    static char* ptr;
    static int i = 0;
    int j = 0, start;

    if (str != NULL)
    {
        ptr = str;
        i = 0;    
    }

    if (ptr == NULL)    
        return NULL;

    start = i;

    while (ptr[i])
    {
        j = 0;

        while (delim[j])
        {
            if (delim[j] == ptr[i])
            {
                ptr[i] = '\0';
                i++;          
                return ptr + start;
            }
            else
            {
                j += 1;
            }
        }

        i += 1;
    }


    if (ptr[start] == '\0') {
        ptr = NULL;
        return NULL;
    }
    {
        char *token = ptr + start;
        ptr = NULL;   
        return token;
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
