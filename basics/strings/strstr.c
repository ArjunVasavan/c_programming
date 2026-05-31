#include <stdio.h>

char* mystrstr( char* main ,  char* sub)
{
    int i = 0;

    while ( main[i] )
    {

        if ( main[i] == sub[0] )
        {
            int k = i + 1;
            int j = 1;              // <-- start at 1 since sub[0] already matched

            while ( sub[j]  )
            {
                if ( sub[j] != main[k] )
                {
                    break;
                }
                j+=1;
                k+=1;

            }
            if (sub[j] == '\0')     // <-- only return when full match
                return main + i;
        }

    i+=1;

    }

    return NULL;
}

int main()
{
    char main[50],sub[50];
    printf("Enter the string : ");
    scanf("%[^\n]",main);
    printf("Enter the sub string : ");
    scanf(" %[^\n]",sub);

    char* ret =  mystrstr(main,sub);

    if ( ret != NULL )
    {
        printf("%s\n",ret);
    }
}

