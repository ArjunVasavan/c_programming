#include <stdio.h>

char* rev ( char* str ,int  start ,int  end,int i )
{
    if ( start < end )
    {
        char temp = str[start];

        str[start] = str[end];

        str[end]  = temp;

        start+=1;
        end-=1;
    rev (str,start,end,i);
    }

    str[i] = '\0';

    return str;

}



int main()
{
    char str[60];
    printf("Enter The String -> ");
    scanf("%[^\n]",str);

    int i = 0;

    while ( str[i] )
    {
        i+=1;
    }

    char* ret = rev(str,0,i-1,i);

    printf("%s \n",ret);

}


