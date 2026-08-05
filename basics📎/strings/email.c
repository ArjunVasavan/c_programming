#include <stdio.h>

char* vowel ( char* str )
{
    char vow[] = "@.";

    int i = 0;

    while(str[i])
    {

        int j = 0;

        while (vow[j])
        {
            if ( str[i] == vow[j] )
            {

                int k = i;

                while ( str[k] )
                {
                    str[k] = str[k+1];

                    k++;
                }

            }
            else
            {
                j++;
            }
        }



        i++;
    }

    return str;

}

int main()
{
    char str[50];

    printf("Enter an EMAIL address -> ");
    scanf("%[^\n]",str);

    char* ret= vowel(str);
    {
        printf("Result -> %s\n",ret);
    }
}

