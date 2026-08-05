#include <stdio.h>
int mystrlen ( char *  );
int main()
{
    char str[20];
    printf("Enter the string! : ");
    scanf("%[^\n]",str);

    printf("length of the string --> %d\n",mystrlen(str));
}

int mystrlen ( char* ptr )
{

    int i = 0 , count = 0;

    while ( ptr[i] )
    {
        count+=1;
        i+=1;

    }

    return count;

}

