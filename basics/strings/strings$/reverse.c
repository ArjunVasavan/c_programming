#include <stdio.h>

char* rev ( char* str )
{
    int i = 0;

    while (  str[i] )
    {
        i+=1;
    }

    int n = i - 1;

    i = 0;

    while ( i <= n/2 )
    {
        char temp = str[i];
        str[i] = str[n - i];
        str[n-i] = temp;
        i+=1;
    }

    return str;

}

int main()
{
    char str[50];
    printf("Enter an String => ");
    scanf("%[^\n]",str);

    printf("Reversed string is => %s\n",rev(str));
}

