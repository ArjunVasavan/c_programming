#include <stdio.h>

int main()
{
    int n = 4;
    int k = n;

    for (int i = 0; i < n; i++)
    {
    
        for (int space = 0; space < i; space++)
        {
            printf("  ");
        }

        for (int j = 0; j < 2 * (n - i) - 1; j++)
        {
            if (i == 0 || j == 0 || j == 2 * (n - i) - 2)
            {
                printf("%d ",k);
            }
            else
            {
                printf("  ");
            }
        }

        printf("\n");
        k--;
    }

}

