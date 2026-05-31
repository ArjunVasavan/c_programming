#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of bits: ");
    scanf("%d", &n);

    char binary[n + 1];
    for (int i = 0; i < n; i++)
        binary[i] = '0';
    binary[n] = '\0';

    for (int count = 0; count < (1 << n); count++) {
        printf("%s\n", binary);

        // increment binary number
        int bit = n - 1;
        while (bit >= 0 && binary[bit] == '1') {
            binary[bit] = '0';
            bit--;
        }
        if (bit >= 0)
            binary[bit] = '1';
    }

    return 0;
}

