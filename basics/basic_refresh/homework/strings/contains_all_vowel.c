#include <stdio.h>

void contain (char* str)
{
    char vowel[] = "aeiou";

    int i = 0;
    int j = 0;
    while ( vowel[j] )
    {
        if ( str[i] == vowel[j] || str[i] == vowel[j]-32 )
        {
            i=0;
            j+=1;
        }
        else
        {
            i+=1;
        }

        if ( str[i] == '\0' )
        {
            break;
        }

    }

    if ( vowel[j] == '\0' )
    {
        printf("Accepted\n");
    }
    else
    {
        printf("Not accepted\n");
    }

}
int main()
{
    char str[60];
    printf("Enter The String -> ");
    scanf("%[^\n]",str);

    contain(str);
}


