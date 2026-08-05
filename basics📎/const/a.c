#include <stdio.h>
int main()
{
    char str[8] = "Hello";
    char *const p = str;
    *p = 'M';
    printf("%s\n", str);
    return 0;
}
