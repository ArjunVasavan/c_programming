#include <stdio.h>

char* hex (char* str,int n)
{
    int i = 0;

    while( 1 )
    {
        int rem = n % 16;

        if ( rem >= 10 )
        {
            str[i]=rem+55;
        }
        else
        {
            str[i] = rem+48;
        }

        n /= 16;

        i+=1;

        if ( n < 16 )
        {
            if ( n < 10 )
            {
                str[i] = n + 48;
            }
            else
            {
                str[i] = n + 55;
            }

            break;
        }
    }

    return str;


}

void reverse (char* str , int end , int start )
{
    while (  )
}
int main()
{
    char str[50] = {'\0'};

    printf("%s",hex(str,12345));
}

