#include <stdio.h>
char* mystrcpy ( char* des,const char* src );
int main()
{
    char src [ 50 ];

    printf("Enter the string : ");
    scanf("%[^\n]",src);

    char des [ 50 ];

    char* ret = mystrcpy ( des , src );

    printf("%s",ret);
}

char* mystrcpy ( char* des,const char* src )
{
    int i = 0 ;

    while ( src[i] )
    {
        des[i] = src[i];
        i+=1;
    }

    des[i] = '\0';

    return des;
}
