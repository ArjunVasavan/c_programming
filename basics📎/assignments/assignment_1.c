#include <stdio.h>
int main()
{
    int n1, n2, n3;

    printf("Enter n1 n2 n3: ");
    scanf("%d %d %d", &n1, &n2, &n3);

    if (n1 > n2)
    {
        if (n1 < n3)
            printf("middle : %d\n", n1);   // n2 < n1 < n3
        else  // n1 >= n3
        {
            if (n2 > n3)
                printf("middle : %d\n", n2); // n3 < n2 < n1
            else
                printf("middle : %d\n", n3); // n2 < n3 < n1
        }
    }
    else  // n1 <= n2
    {
        if (n1 > n3)
            printf("middle : %d\n", n1);   // n3 < n1 < n2
        else  // n1 <= n3
        {
            if (n2 < n3)
                printf("middle : %d\n", n2); // n1 < n2 < n3
            else
                printf("middle : %d\n", n3); // n1 < n3 < n2
        }
    }

    return 0;
}

