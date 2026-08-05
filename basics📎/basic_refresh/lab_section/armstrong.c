#include <stdio.h>

int powr(int base, int exp);

int main() {
    int n, temp, rem, result = 0, count = 0;

    printf("Enter a number: ");
    scanf("%d", &n);

    temp = n;


    while (temp != 0) {
        temp /= 10;
        count++;
    }

    temp = n;

    while (temp != 0) {
        rem = temp % 10;
        result += powr(rem, count);
        temp /= 10;
    }

    printf("Result: %d\n", result);

    if (result == n)
        printf("It's an Armstrong number\n");
    else
        printf("It's not an Armstrong number\n");

    return 0;
}

int powr(int base, int exp) 
{
    int power = 1;
    for (int i = 0; i < exp; i++) 
    {
        power *= base;
    }
    return power;
}

