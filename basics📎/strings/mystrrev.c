#include <stdio.h>

char* mystrrev( char* str)
{
    int i = 0;

    while ( str[i] )
    {
        i+=1;
    }

    int n = i;

    int j = 0;

    while ( n % 2 != 0 ? j < (n - 1 ) / 2 :  j < n / 2  )
    {

        char temp = str[j];

        str[j] = str[n-j-1];

        str[n-j-1] = temp;

        j+=1;

    }

    str[n] = '\0';

    return str;
}

int main()
{
    char str1[50];
    
    printf("Enter String1--> ");

    scanf("%[^\n]",str1);


    printf("%s --> result from my_strrev ! ",mystrrev(str1));
}

