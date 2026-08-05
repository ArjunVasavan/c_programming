#include <stdio.h>
#include <stdint.h>

// Without packed: compiler adds padding bytes
typedef struct {
    uint8_t  a;    // 1 byte + 3 padding
    uint32_t b;    // 4 bytes
    uint8_t  c;    // 1 byte + 3 padding
} Normal_t;        // sizeof = 12

// With packed: no padding — safe for network/hardware frames
typedef struct __attribute__((packed)) {
    uint8_t  a;
    uint32_t b;
    uint8_t  c;
} Packed_t;        // sizeof = 6

int main() {
    printf("Normal=%zu Packed=%zu\n", sizeof(Normal_t), sizeof(Packed_t));
}
// Output: Normal=12 Packed=6
