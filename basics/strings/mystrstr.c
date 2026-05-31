#include <stdio.h>

char* mystrstr(char* main,char* sub)
{

    int i = 0;

    while ( main[i] )
    {

        if ( main[i] == sub[0] )
        {
            int k = i+1;
            int j = 1;

            while ( sub[j] )
            {

                if ( main[k] != sub[j] )
                {
                    break;
                }

                j++;
                k++;
            }

            if (sub[j] == '\0')
            {
                return main + i;
            }


        }

        i++;
    }

    return NULL;

}

int main()
{
    char main[50],sub[50];

    printf("Enter Main String : ");
    scanf("%[^\n]",main);

    printf("Enter the sub string : ");
    scanf(" %[^\n]",sub);

    char* ret = mystrstr(main,sub);

    if ( ret != NULL )
    {
        printf("%s\n",ret);
    }
    else
    {
        printf("NULL IS THE OUTPUT THUS NOTHING FOUND\n");
    }
}

