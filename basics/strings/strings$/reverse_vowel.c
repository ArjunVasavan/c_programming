#include <stdio.h>
#include <string.h>
char* fun(char str[] )
{
    char vow[] = "aeiou";

    int len = strlen(str) - 1;

    printf("Len i got is %d\n",len);
    int i = 0;    
    int ff = 0 ,fb = 0 ;
    while ( i <= len/2 )
    {
        int holdf;
        int holdb;
        int j = 0;

        while( vow[j] )
        {
            if ((ff == 0) && (vow[j] == str[i] || vow[j] - 32 == str[i] ))
            {
                ff = 1;
                holdf = i;
            }
            if ((fb ==0) && ( vow[j] == str[len - i - 1] || vow[j] - 32 == str[len - i - 1] ))
            {
                fb = 1;
                holdb = len - i - 1;
            }
            j+=1;
        }

        if ( ff == 1 && fb == 1 )
        {
            char temp = str[holdf];
            str[holdf] = str[holdb];
            str[holdb] = temp;
            ff = 0;
            fb = 0;
        }
        i+=1;
    }
    

    return str;
}

int main()
{
    char str[100];
    printf("Enter the string : ");
    scanf("%[^\n]",str);
    
    printf("Output is -> %s \n",fun(str));
}

