#include <stdio.h>
#include <string.h>


int main(void) {
char s1[6] = "hello";
strncat(s1, "WORLD", 3);
printf("%s\n", s1);
return 0;
}
