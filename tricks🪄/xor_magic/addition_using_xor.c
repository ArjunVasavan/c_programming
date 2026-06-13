#include <stdio.h>

int increment(int x) {
    int carry = 1;

    while (carry != 0) {
        int temp = x ^ carry;          // sum without carry
        carry = (x & carry) << 1;      // carry
        x = temp;
    }

    return x;
}

int main() {
    int i = 5;

    i = increment(i);

    printf("%d\n", i);  // Output: 6

    return 0;
}
