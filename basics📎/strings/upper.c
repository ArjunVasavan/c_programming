#include <stdio.h>
int ucase (const char *  );
int main()
{
    char str[20];
    printf("Enter the string! : ");
    scanf("%[^\n]",str);

    printf("number of the uppercase --> %d\n",ucase(str));
}

int ucase (const char* ptr )
{

    int i = 0 , count = 0;

    while ( ptr[i] )
    {
        if ( ptr[i] >= 65 && ptr[i] <= 90 )
        {
        count+=1;
        }
        i+=1;

    }

    return count;

}

