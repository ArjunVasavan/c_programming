#include <stdio.h>


int main(void) {
char s[] = "\x41\x42"; /* 'A' 'B' */
printf("%c %c\n", s[0], s[1]);
return 0;
}
