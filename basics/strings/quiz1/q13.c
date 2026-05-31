#include <stdio.h>


int main(void) {
char *p = "ABC";
printf("%c %c\n", *p, *++p);
return 0;
}
