#include <stdio.h>

char* mystrcat(char* str1, const char* str2)
{
    int i = 0;

    while ( str1[i] )
    {
        i+=1;
    }

    int j = 0;

    while ( str2[j] )
    {
        str1[i] = str2[j];
        i+=1;
        j+=1;
    }

    return str1;
}

int main()
{
    char str1[50];
    char str2[50];

    printf("Enter an String 1 --> ");
    scanf("%[^\n]",str1);
    printf("Enter an String 2 --> ");
    scanf(" %[^\n]",str2);

    char* ret = mystrcat(str1,str2);

    printf("Result --> %s",ret);
}

