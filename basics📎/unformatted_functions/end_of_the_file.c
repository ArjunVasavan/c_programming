#include <stdio.h>

int main() {
    char ch;

    printf("Enter Anything extcept ctrl+d it wont stop \n");
    while  ( ( ch = getc(stdin) ) != EOF ) {
        putchar(ch);
    }

    printf("You Have used EOF here \n");
}

