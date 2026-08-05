#include <stdio.h>

int mystrcasecmp( const char * str1 , const char * str2 )
{
    int i = 0;

    while ( str1[i] == str2[i] || str1[i]-32 == str2[i] || str1[i] == str2[i]-32 )
    {
        if ( str1[i] !=  str2[i] )
        {
            return 0;
        }

        i+=1;
    }

    return str1[i] - str2[i];
}

int main()
{
    char str1[50],str2[50];
    
    printf("Enter String1--> ");

    scanf("%[^\n]",str1);

    printf("Enter String2 --> ");

    scanf(" %[^\n]",str2);

    printf("%d --> result from my_strcasecmp ! ",mystrcasecmp(str1,str2));
}

