#include <stdio.h>

int main(void) {
    int n = 3;               // change this to any small n for testing
    char binary[n + 1];
    for (int i = 0; i < n; i++) binary[i] = '0';
    binary[n] = '\0';

    printf("Start: n = %d, total = %d\n\n", n, (1 << n));

    for (int step = 0; step < (1 << n); step++) {
        printf("=== Step %d ===\n", step);
        printf("Before increment: binary = %s\n", binary);
        printf("Check to increment: bit starts at index = %d (rightmost)\n", n-1);

        int bit = n - 1;

        // Show the while loop evaluation exactly
        int loop_iter = 0;
        while (1) {
            int cond_bit_ge_0 = (bit >= 0);
            int cond_bit_is_1 = (cond_bit_ge_0 ? (binary[bit] == '1') : 0);
            printf("  [while-eval %d] (bit >= 0) => %s", loop_iter, cond_bit_ge_0 ? "true" : "false");
            if (cond_bit_ge_0) printf(", (binary[%d] == '1') => %s\n", bit, cond_bit_is_1 ? "true" : "false");
            else printf("\n");

            if (!(cond_bit_ge_0 && cond_bit_is_1)) {
                // while condition false -> break
                printf("  -> while condition false, exit while with bit = %d\n", bit);
                break;
            }

            // body: binary[bit] == '1'
            printf("  -> while body: binary[%d] was '1' -> turning to '0'\n", bit);
            binary[bit] = '0';
            bit--;
            loop_iter++;
            printf("     after body: binary = %s, new bit = %d\n", binary, bit);
        }

        // After while, if bit >= 0 then we flip that 0 -> 1
        if (bit >= 0) {
            printf("  Now (bit >= 0) is true (bit = %d). binary[%d] was '%c' -> turning to '1'\n",
                   bit, bit, binary[bit]);
            binary[bit] = '1';
            printf("  After flip: binary = %s\n", binary);
        } else {
            printf("  Now (bit >= 0) is false (bit = %d). This is overflow -> all bits were reset to 0.\n", bit);
        }

        printf("After increment: binary = %s\n\n", binary);
    }

    return 0;
}

