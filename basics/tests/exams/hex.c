#include <stdio.h>

int main()
{
    unsigned int num;

    printf("Enter a hexadecimal number: ");
    scanf("%x", &num);   // input in hex (like 2F)

    printf("Binary (32 bits): ");

    // Run exactly 32 times
    for (int i = 31; i >= 0; i--)
    {
        // get remainder (0 or 1)
        unsigned int bit = num % 2;

        // store it by printing in reverse order
        // but since we cannot go back, we must build the number first
        // easiest trick: use a second variable

        // Actually: Instead of arrays, let’s use division with power of 2
        unsigned int power = 1;
        for (int j = 0; j < i; j++)
        {
            power *= 2; // calculate 2^i
        }

        if (num / power % 2 == 1)
            printf("1");
        else
            printf("0");
    }

    return 0;
}

