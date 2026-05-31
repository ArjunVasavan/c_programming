#include <stdio.h>

int  vowel ( char* str )
{
    char vow[] = "abcdefghijklmnopqrstuvwxyz";

    int i = 0;

    while(vow[i])
    {

        int j = 0;

        int count = 0;

        while (str[j])
        {

            if ( vow[i] == str[j] || vow[i] == str[j]-32 )
            {   
                continue;
            }
            else
            {
                j++;
            }
        }



        i++;
    }

    if ( vow[i] == '\0' )
    {
        return 1;
    }
    else
    {
        return 0;
    }

}

int main()
{
    char str[50];

    printf("Enter an String -> ");
    scanf("%[^\n]",str);

    int  ret= vowel(str);

    if ( ret == 1 )
    {
        printf("its an pangram\n");
    }
    else
    {
        printf("not an pangram\n");
    }
}

