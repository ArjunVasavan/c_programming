// Union maps a peripheral control register to both a full byte
// and individual bitfields — allowing atomic full-register writes
// alongside precise single-bit control without separate variables

#include <stdio.h>
#include <stdint.h>

typedef union {
    uint8_t raw;
    struct {
        uint8_t enable : 1;
        uint8_t mode   : 2;
        uint8_t irq    : 1;
    } bits;
} CtrlReg_t;

int main() {
    CtrlReg_t reg;

    reg.raw = 0x00;
    printf("Reset  : raw=0x%02X enable=%d mode=%d irq=%d\n",
            reg.raw, reg.bits.enable, reg.bits.mode, reg.bits.irq);

    reg.bits.enable = 1;
    reg.bits.mode   = 2;
    reg.bits.irq    = 1;
    printf("Config : raw=0x%02X enable=%d mode=%d irq=%d\n",
            reg.raw, reg.bits.enable, reg.bits.mode, reg.bits.irq);
}
// Output:
// Reset  : raw=0x00 enable=0 mode=0 irq=0
// Config : raw=0x0D enable=1 mode=2 irq=1
