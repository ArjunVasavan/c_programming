#include <stdio.h>

/* this is not an string its an character array it doesnt havr '\0' character in it */ 

int main(void) {
char s[] = { 'x', 'y', 'z' };
printf("%s\n", s);
return 0;
}
