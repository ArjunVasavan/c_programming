#include <stdio.h>
#include <stdint.h>

// Abstract hardware — swap drivers without changing app code
typedef struct {
    const char *name;
    void (*init)(void);
    void (*send)(uint8_t);
} Driver_t;

void uart_init(void) { printf("UART init\n"); }
void uart_send(uint8_t d) { printf("UART send: %d\n", d); }

int main() {
    Driver_t drv = {"UART", uart_init, uart_send};
    drv.init();
    drv.send(0x42);
}
// Output:
// UART init
// UART send: 66
