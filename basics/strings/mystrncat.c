#include <stdio.h>

char* mystrcat(char* str1, const char* str2 , const int n )
{
    int i = 0;

    while ( str1[i] )
    {
        i+=1;
    }

    int j = 0;

    while ( str2[j] && j < n )
    {
        str1[i] = str2[j];
        i+=1;
        j+=1;
    }

    str1[i] = '\0';

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

    int n;
    printf("Enter the n value --> ");
    scanf("%d",&n);

    char* ret = mystrcat(str1,str2,n);

    printf("Result --> %s",ret);
}

