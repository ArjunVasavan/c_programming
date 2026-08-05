#include <stdio.h>

int main()
{
    int n;
    int temp;
    int i;
    int j;
    int k;
    int c = 0;
    int store = 1;

    printf("Enter the number of lines : ");
    scanf("%d", &n);

    temp = n;

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= (temp - i); j++)
        {
            printf(" ");
        }

        store = 2 * i - 1;  
        for (k = 1; k <= store; k++)
        {
            printf("*");
        }

        printf("\n");
    }

    return 0;
}

