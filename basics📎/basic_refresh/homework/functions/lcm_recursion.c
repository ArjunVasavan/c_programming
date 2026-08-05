#include <stdio.h>

int lcm (int a ,int  b ,int start )
{
    if ( start % a  == 0 && start % b  == 0 )
    {
        return start;
    }
       return lcm(a,b,start+1);
}

int main()
{
    int a = 12 ;
    int b = 4;

    int start = a > b ? a : b;
    printf("%d",lcm(a,b,start));
}

