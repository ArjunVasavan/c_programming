#include <stdio.h>
#include <stdint.h>
// Track system state and error in one place
typedef struct {
    uint8_t  state;   // 0=idle 1=run 2=error
    uint32_t err_code;
    uint8_t  retries;
} FSM_t;

int main() {
    FSM_t fsm = {0, 0, 0};
    fsm.state    = 1;           // start running
    fsm.err_code = 0xDEAD;     // error occurred
    fsm.state    = 2;
    printf("State=%d Err=0x%X Retries=%d\n", fsm.state, fsm.err_code, fsm.retries);
}
// Output: State=2 Err=0xDEAD Retries=0
