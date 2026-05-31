#include <stdio.h>
int sum (const char *  );
int main()
{
    char str[20];
    printf("Enter the string! : ");
    scanf("%[^\n]",str);

    printf("sum is  --> %d\n",sum (str));
}

int sum (const char* ptr )
{

    int i = 0 , sum = 0;

    while ( ptr[i] )
    {

        if ( ptr[i] >= 48 && ptr[i] <= 57 )
        {
        sum += ( ptr[i] - 48 ) ;
        }
        i+=1;

    }

    return sum;

}

