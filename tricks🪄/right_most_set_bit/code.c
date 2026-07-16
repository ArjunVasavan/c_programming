#include <stdio.h>

int rightmost_set_bit_v1(int x) {
    return x & (-x);
}

int rightmost_set_bit_v2(int x) {
    return x ^ (x & (x - 1));
}

int rightmost_set_bit_position(int x) {
    int bit_value = x & (-x);
    int position = 0;
    while (bit_value > 1) {
        bit_value >>= 1;
        position++;
    }
    return position;
}

int main() {
    int nums[] = {12, 10, 8, 1, 100, 0};
    int count = sizeof(nums) / sizeof(nums[0]);

    for (int i = 0; i < count; i++) {
        int x = nums[i];
        printf("x = %d\n", x);
        printf("  method 1 (x & -x)         -> %d\n", rightmost_set_bit_v1(x));
        printf("  method 2 (x ^ (x & x-1))  -> %d\n", rightmost_set_bit_v2(x));
        printf("  position of that bit      -> %d\n", x == 0 ? -1 : rightmost_set_bit_position(x));
        printf("\n");
    }

    return 0;
}
