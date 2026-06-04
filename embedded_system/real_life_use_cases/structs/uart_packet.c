#include <stdio.h>
#include <stdint.h>
// Pack protocol frame into a single transmittable struct
typedef struct {
    uint8_t  start;
    uint8_t  dev_id;
    uint8_t  data[4];
    uint16_t crc;
} Packet_t;

int main() {
    Packet_t p = {0xAA, 0x01, {1,2,3,4}, 0xFFFF};
    printf("Start=0x%X Dev=%d CRC=0x%X\n", p.start, p.dev_id, p.crc);
}
// Output: Start=0xAA Dev=1 CRC=0xFFFF
