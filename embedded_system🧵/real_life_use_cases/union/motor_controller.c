// Union overlays a 16-bit status register with named fault bitfields,
// enabling full fault-word clears in a single assignment
// while retaining readable per-fault access without manual bit masking

#include <stdio.h>
#include <stdint.h>

typedef union {
    uint16_t word;
    struct {
        uint16_t overvoltage  : 1;
        uint16_t undervoltage : 1;
        uint16_t overtemp     : 1;
        uint16_t comm_fault   : 1;
        uint16_t motor_stall  : 1;
    } flags;
} Status_t;

int main() {
    Status_t s;

    s.word = 0x0000;
    printf("Clear : 0x%04X\n", s.word);

    s.flags.overtemp   = 1;
    s.flags.comm_fault = 1;
    printf("Fault : 0x%04X overtemp=%d comm=%d\n",
            s.word, s.flags.overtemp, s.flags.comm_fault);

    if (s.flags.overtemp)
        printf("ACTION: Shutdown — over temperature!\n");

    s.word = 0x0000;
    printf("Reset : 0x%04X\n", s.word);
}
// Output:
// Clear : 0x0000
// Fault : 0x0014 overtemp=1 comm=1
// ACTION: Shutdown — over temperature!
// Reset : 0x0000
