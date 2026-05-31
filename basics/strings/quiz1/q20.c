#include<stdio.h>
int main(void) {
char s[] = "abc";
char *p = s + 1;
*(p++) = 'X';
printf("%s\n", s);
return 0;
}
