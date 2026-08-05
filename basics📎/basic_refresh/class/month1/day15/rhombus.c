#include <stdio.h>

int main()
{
    int n = 4;
    int i, j;

    // Top half (including middle line)
    for (i = 1; i <= n; i++)
    {
        // Leading spaces
        for (j = 1; j <= n - i; j++)
            printf(" ");

        // Left stars
        for (j = 1; j <= i; j++)
            printf("*");

        // Right stars
        for (j = 1; j < i; j++)
            printf("*");

        printf("\n");
    }

    // Bottom half
    for (i = 1; i < n; i++)
    {
        // Leading spaces
        for (j = 1; j <= i; j++)
            printf(" ");

        // Left stars
        for (j = 1; j <= n - i; j++)
            printf("*");

        // Right stars
        for (j = 1; j < n - i; j++)
            printf("*");

        printf("\n");
    }

    return 0;
}

