#include <stdio.h>

char* mystrtok(char* str,char* del)
{
    static char* search;

    if ( str != NULL  )
    {
        search = str;
    }
    char* start = search;
    while ( *search )
    {
        int j = 0;

        while (del[j])
        {

            if ( del[j] == *search )
            {
                break;
            }

            j+=1;
        }
    
        if ( del[j] != '\0' )
        {
            *search = '\0';
            return start;
        }

        search++;
    }


}
int main()
{
    printf("Enter an String : ");
    char str[50];
    scanf("%[^\n]",str);

    char del[10];
    printf("Enter The Delimeter : ");
    scanf(" %[^\n]",del);

    char* ret = mystrtok(str,del);
    while (ret != NULL)
    {
        printf("%s",ret);
        ret = mystrtok(NULL,del);
    }
}
