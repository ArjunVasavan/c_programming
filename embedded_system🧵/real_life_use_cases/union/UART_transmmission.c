// Union overlays float and byte array on same memory location,
// enabling direct byte-level access to floating point data
// without casting or extra memory — critical for UART/CAN transmission

#include <stdio.h>
#include <stdint.h>

typedef union {
    float   value;
    uint8_t bytes[4];
} FloatUnion_t;

int main() {
    FloatUnion_t temp;
    temp.value = 36.5f;

    printf("Float : %.2f\n", temp.value);
    printf("Bytes : %02X %02X %02X %02X\n",
            temp.bytes[0], temp.bytes[1],
            temp.bytes[2], temp.bytes[3]);
}
// Output:
// Float : 36.50
// Bytes : 00 00 12 42
