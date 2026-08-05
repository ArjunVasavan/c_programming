#include <stdio.h>
#include <stdint.h>
// Group sensor readings into one unit
typedef struct {
    float   temp;
    float   humidity;
    uint8_t sensor_id;
} Sensor_t;

int main() {
    Sensor_t s = {36.5f, 65.2f, 1};
    printf("Sensor %d: %.1f°C, %.1f%%\n", s.sensor_id, s.temp, s.humidity);
}
// Output: Sensor 1: 36.5°C, 65.2%
