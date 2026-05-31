#include <stdio.h>

int main() {
    int ch;   // store characters (int, not char, because EOF is -1)

    printf("Type something (press Enter to stop):\n");

    while ((ch = getchar()) != '\n') {   // keep reading until Enter is pressed
        putchar(ch);  // immediately print the character back
    }

    return 0;
}

