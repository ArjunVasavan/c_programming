#include <stdio.h>

int vowel ( char* str )
{
    char vowels[] = "aeiouAEIOU";

    int i = 0;

    int count = 0;

    for ( int i = 0 ; str[i] ; i++ )
    {
        for ( int j = 0 ; vowels[j] ; j++ )
        {
            if ( vowels[j] == str[i] )
            {
                count+=1;
            }
        }
    }

    return count;

}

int main()
{
    printf("Enter the String --> ");
    char str[50];

    scanf("%[^\n]",str);

    printf("The Total Number of Vowels are %d ",vowel(str));
}

