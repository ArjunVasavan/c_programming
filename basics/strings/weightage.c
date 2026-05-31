#include <stdio.h>

char*  weight(char* str1 ,char* str2 );
int main()
{
    char str1[50],str2[50];

    printf("Enter str1 and str2 --> ");
    scanf("%[^\n] %[^\n]",str1,str2);

    printf("The result of heighest weightage is %s ",weight( str1 , str2 ));
}
char*  weight(char* str1 ,char* str2 )
{
    int sum1 = 0 , sum2 = 0;
    int i = 0;
    while (str1[i])
    {
        sum1+=str1[i];
        i+=1;
    }

    i = 0;

    while ( str2[i] )
    {
        sum2+=str2[i];
        i+=1;
    }

    if ( sum1 > sum2 )
    {
        return str1;
    }
    else if ( sum1 < sum2 )
    {
        return str2;
    }
}

