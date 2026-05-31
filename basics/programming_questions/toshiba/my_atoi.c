#include <stdio.h>
#include <ctype.h>

int my_atoi(const char *str)
{
    int result = 0;
    int sign = 1;
    int i = 0;

    // Skip leading spaces
    while (isspace(str[i]))
        i++;

    // Handle sign
    if (str[i] == '-')
    {
        sign = -1;
        i++;
    }
    else if (str[i] == '+')
    {
        i++;
    }

    // Convert digits
    while (isdigit(str[i]))
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }

    return sign * result;
}

int main()
{
    char str[] = "   -4567abc";
    printf("%d\n", my_atoi(str));   // -4567
}
