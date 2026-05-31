#include <stdio.h>

int vowel( char* str )
{
    char vow[] = "aeiouAEIOU";

    int i = 0;

    int count;

    while ( str[i] )
    {
        int j = 0;

        while ( vow[j] )
        {
            if ( str[i] == vow[j] )
            {
                count+=1;
            }

            j+=1;
        }
        i+=1;
    }

    return count;

}

int main()
{
    char str[60];
    printf("Enter The String -> ");
    scanf("%[^\n]",str);
    
    printf("%d is the total count of vowels\n",vowel(str));
}


