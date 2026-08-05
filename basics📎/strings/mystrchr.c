#include <stdio.h>

char* mystrchr( char* str1 ,const char ch)
{
    int i = 0 ;

    while ( str1[i] )
    {
        if ( str1[i] == ch )
        {
            
            return str1 + i;
        }

        i+=1;
    }

    return NULL;
}

int main()
{
    char str1[50],str2[50];
    
    printf("Enter String1--> ");

    scanf("%[^\n]",str1);
    char ch;
    printf("Enter The Character you wanna find  --> ");

    scanf(" %c",&ch);

    printf("%p --> Adress of str1 ! ",str1);
    printf("%p --> result from my_strchr ! ",mystrchr(str1,ch));
}

