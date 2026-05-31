#include <stdio.h>
#include <string.h>
int main()
{
    char str1[50] ;
    char str2[50] ;

    printf("Enter String 1 : ");
    scanf("%[^\n]",str1);

    printf("Enter String 2 : ");
    scanf(" %[^\n]",str2); //here i just put an space before [^\n] thus we dont want to use fpurge

    printf("The Result is [str1 - str2] -->  %d \n",strcmp(str1,str2));

    strcmp(str1,str2)==0?printf("Thus its Equal\n"):printf("Thus its not Equal \n");


}

