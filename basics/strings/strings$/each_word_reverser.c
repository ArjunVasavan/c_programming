#include <stdio.h>

char* rev ( char* str,int f,int l  )
{
    while ( f <= l )
    {
        int temp = str[f];
        str[f] = str[l];
        str[l] = temp;

        l-=1;
        f+=1;
    }

    return str;
}

int main()
{
    char str[50];

    printf("Enter an string => ");
    scanf("%[^\n]",str);

    printf("Enter index to reverse => first and last =>  ");
    int f,l;

    scanf("%d %d",&f,&l);

    printf("Word reverser output => %s \n",rev(str,f,l));
}

