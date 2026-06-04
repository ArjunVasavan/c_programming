#include <stdio.h>
#include <stdint.h>
// Store task metadata in a table — loop to register all tasks
typedef struct {
    const char *name;
    uint8_t     priority;
    uint32_t    period_ms;
} Task_t;

int main() {
    Task_t tasks[] = {{"Sensor",2,100}, {"Comms",3,50}, {"Display",1,500}};
    for (int i = 0; i < 3; i++)
        printf("Task: %-8s Pri=%d Period=%lums\n", tasks[i].name, tasks[i].priority, tasks[i].period_ms);
}
// Output:
// Task: Sensor   Pri=2 Period=100ms
// Task: Comms    Pri=3 Period=50ms
// Task: Display  Pri=1 Period=500ms
