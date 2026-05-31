#include <stdio.h>

int main()
{
    char str[200];
    
    printf("Enter the contents you want to write :");
    scanf("%[^\n]",str);
    
    FILE* fptr = fopen("text.txt","w");
    char ch;
    
    int i = 0;
    
    while ( str[i] != '\0' )
    {
        ch = str[i];
        fputc(ch,fptr);
        i+=1;
    }
    
    fclose(fptr);
    
    FILE* rptr = fopen("text.txt","r");
    printf("The contents that you have wrotten are : \n");
    
    while ( (ch = fgetc(fptr)) != EOF )
    {
        putchar(ch);
    }
    
    fclose(rptr);
}
