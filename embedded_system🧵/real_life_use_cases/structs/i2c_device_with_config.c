#include <stdio.h>
#include <stdint.h>

// Real devices have both identity and config — nest them
typedef struct {
    uint32_t clock_hz;
    uint8_t  word_size;
} SPIConfig_t;

typedef struct {
    uint8_t    addr;
    SPIConfig_t config;
} SPIDevice_t;

int main() {
    SPIDevice_t dev = {0x20, {8000000, 8}};
    printf("Addr=0x%X Clock=%uHz Bits=%d\n",
           dev.addr, dev.config.clock_hz, dev.config.word_size);
}
// Output: Addr=0x20 Clock=8000000Hz Bits=8
