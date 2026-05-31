#include <stdio.h>

void dec_to_hex(int n)
{
    char str[50];
    int i = 0;
    while(1)
    {
        int rem = n % 16;

        if ( rem >= 10 )
        {
            str[i] = rem + 55;
        }
        else
        {
            str[i] = rem + 48;
        }
        n = n / 16;

        i+=1;

        if ( n < 16 )
        {

            if ( n >= 10 )
            {
                str[i] = n + 55;
                break;
            }
            else
            {
                str[i] = n + 48;
                break;
            }
        }
    }

    str[i+1] = '\0';

    int start = 0;
    int end = i;

    while ( start < end )
    {
        int temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start+=1;
        end-=1;
    }

    printf("%s \n",str);
}



int main()
{
    int n;
    printf("Enter The number -> ");
    scanf("%d",&n);

    dec_to_hex(n);

}


