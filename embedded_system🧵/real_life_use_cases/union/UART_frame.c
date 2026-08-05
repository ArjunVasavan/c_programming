// Union exposes the same packet memory as both structured named fields
// and a contiguous raw byte array — allowing readable field-level
// construction while passing raw[] directly to DMA with zero memcpy overhead

#include <stdio.h>
#include <stdint.h>

typedef union {
    struct {
        uint8_t  start;
        uint8_t  dev_id;
        uint8_t  payload[4];
        uint16_t crc;
    } fields;
    uint8_t raw[8];
} Frame_t;

int main() {
    Frame_t f;
    f.fields.start      = 0xAA;
    f.fields.dev_id     = 0x01;
    f.fields.payload[0] = 0x11;
    f.fields.payload[1] = 0x22;
    f.fields.payload[2] = 0x33;
    f.fields.payload[3] = 0x44;
    f.fields.crc        = 0xFFFF;

    printf("Fields : start=0x%02X dev=%d crc=0x%04X\n",
            f.fields.start, f.fields.dev_id, f.fields.crc);

    printf("Raw    : ");
    for (int i = 0; i < 8; i++)
        printf("%02X ", f.raw[i]);
    printf("\n");
}
// Output:
// Fields : start=0xAA dev=1 crc=0xFFFF
// Raw    : AA 01 11 22 33 44 FF FF
