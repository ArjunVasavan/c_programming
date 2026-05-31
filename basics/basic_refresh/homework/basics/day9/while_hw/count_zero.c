#include <stdio.h>

int main()
{
    int n;
    int count = 0;
    int check = 0;

    printf("Enter n : ");
    scanf("%d", &n);

    while (n != 0)
    {
        check = n % 10;         

        if (check == 0)
        {
            count += 1;     
        }

        n = n / 10;             
    }

    printf("%d \n", count);
}

