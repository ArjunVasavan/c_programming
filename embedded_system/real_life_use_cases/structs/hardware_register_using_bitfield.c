#include <stdint.h>
#include <stdio.h>
// Map individual bits to hardware control pins
typedef struct {
    uint8_t enable : 1;   // bit 0
    uint8_t mode   : 2;   // bits 1-2
    uint8_t error  : 1;   // bit 3
} CtrlReg_t;

int main() {
    CtrlReg_t reg = {1, 2, 0};
    printf("Enable=%d Mode=%d Error=%d\n", reg.enable, reg.mode, reg.error);
}
// Output: Enable=1 Mode=2 Error=0
