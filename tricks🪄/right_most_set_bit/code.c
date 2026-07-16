#include <stdio.h>

int rightmost_set_bit_v1(int x) {
    return x & (-x);
}

/* NOTE: x & ( - x )
 * computer's store negative number's in 2's compliment
 * to get -x you have to flip every bit and add 1 with it
 * adding 1 to complimented cause's trailing of 1 till it reaches an 0
 * the first 0 it hit's is flipped to 0
 * now when we and with the original number we get the right most bit as set
 */

int rightmost_set_bit_v2(int x) {
    return x ^ (x & (x - 1));
}

/* NOTE: x ^ ( x & (x - 1 ))
 * x & ( x - 1 ) -> this remove's the right most set bit
 * when using exor it give's the high on bit which is opposite
 * so when we done x & ( x - 1 ) the right most bit is gone
 * so when we do xor with the original the original's right most bit is high
 * through this exor will make that right most part as only high and all the rest become's zero
 */

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
