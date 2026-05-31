#include <stdio.h>


int main(void) {
char *p = "12" "34";
printf("%c %c\n", *(p+1), p[2]);
return 0;
}
