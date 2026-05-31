#include <stdio.h>

int mystrcmp( const char *str1 , const char* str2 ,const int n )
{
    int i = 0;


    while ( str1[i] == str2[i] && i < n )
    {
        if ( str1[i] == '\0' )
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
    int n;
    printf("Enter n vale  --> ");

    scanf(" %d",&n);

    printf("%d --> result from my_strcmp ! ",mystrcmp(str1,str2,n));
}

