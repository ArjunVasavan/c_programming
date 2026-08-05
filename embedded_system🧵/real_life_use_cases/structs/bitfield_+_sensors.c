#include <stdio.h>
#include <stdint.h>
// Bitfield flags embedded inside a sensor struct
typedef struct {
    uint8_t ready   : 1;
    uint8_t overrun : 1;
    uint8_t mode    : 2;
} Status_t;

typedef struct {
    float    temp;
    Status_t status;
} Device_t;

int main() {
    Device_t d = {42.0f, {1, 0, 2}};
    printf("Temp=%.1f Ready=%d Overrun=%d Mode=%d\n",
           d.temp, d.status.ready, d.status.overrun, d.status.mode);
}
// Output: Temp=42.0 Ready=1 Overrun=0 Mode=2
