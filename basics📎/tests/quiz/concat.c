#include <stdio.h>
void foo(const char *s)
{
    if (*s)
        foo(s + 1);
    putchar(*s);
}

int main()
{
    int a;
    foo("Hello" "World");
    return 0;
}

