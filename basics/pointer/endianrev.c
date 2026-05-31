#include <stdio.h>

int main()
{

    int x = 0xABCDEF12;
    
    char* ptr = (char*)&x;

    char temp1 = *ptr;

    *ptr = *(ptr+3);

    *(ptr+3) = temp1;

    char temp2 = *(ptr+1);

    *(ptr+1) = *(ptr+2);

    *(ptr+2) = temp2;

    printf("%x",x);
    

}

