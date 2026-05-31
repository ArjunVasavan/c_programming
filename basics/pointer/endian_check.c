#include <stdio.h>

int main()
{
    int x = 0xABCDEF12;

    char* ptr = (char*)&x;

    if ( *ptr == 0xAB )
    {
        printf("The system is an Big Endian \n");
    }
    else
    {
        printf("The system is an little Endian \n");
    }
}
