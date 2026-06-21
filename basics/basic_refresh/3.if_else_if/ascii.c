#include <stdio.h>

int main() {
    char ascii;

    printf("Enter the character: ");
    scanf("%c", &ascii);

    if (ascii >= 'A' && ascii <= 'Z') {
        printf("It is an Uppercase: %c\nIts ASCII value: %d\n", ascii, ascii);
    }
    else if (ascii >= 'a' && ascii <= 'z') {
        printf("It is a Lowercase: %c\nIts ASCII value: %d\n", ascii, ascii);
    }
    else if (ascii >= '0' && ascii <= '9') {
        printf("It is a Digit: %c\nIts ASCII value: %d\n", ascii, ascii);
    }
    else {
        printf("It is a Special Character: %c\nIts ASCII value: %d\n", ascii, ascii);
    }

    return 0;
}
