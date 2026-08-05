#include <stdio.h>
#include <string.h>

void reverse_recursive(char *start, char *end)
{
    if (start >= end)      // base case
        return;

    char temp = *start;
    *start = *end;
    *end = temp;

    reverse_recursive(start + 1, end - 1);
}

int main()
{
    char str[] = "Embedded";

    reverse_recursive(str, str + strlen(str) - 1);

    printf("%s\n", str);

    return 0;
}
