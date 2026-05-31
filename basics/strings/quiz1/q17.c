#include <stdio.h>


int main(void) {
char s[] = "ab\0cd";
printf("%zu %c %c\n", sizeof(s), s[2], s[3]);
return 0;
}
