#include <stdio.h>

void mystrrev(char* str)
{
    int i = 0;
    while (str[i])   // find length
        i++;

    int start = 0;
    int end = i - 1;

    while (start < end)
    {
        char temp = str[start];   // use start
        str[start] = str[end];    // swap with end
        str[end] = temp;

        start++;
        end--;
    }

    printf("%s \n", str);
}

int main()
{
    char str1[50];

    printf("Enter String1--> ");
    scanf("%[^\n]", str1);

    mystrrev(str1);
}

