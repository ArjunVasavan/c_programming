#include <stdio.h>

// Recursive function to reverse a string
char* strrev(char* str, int start, int end)
{
    if (start >= end)  // base case: crossed the middle
        return str;

    // swap characters at start and end
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;

    // recursive call with next indices
    return strrev(str, start + 1, end - 1);
}

int main()
{
    char str[50];

    printf("Enter the STRING: ");
    scanf("%[^\n]", str);

    int length = 0;
    while (str[length] != '\0')  // calculate string length
        length++;

    printf("Reverse is -> %s\n", strrev(str, 0, length - 1));

    return 0;
}

