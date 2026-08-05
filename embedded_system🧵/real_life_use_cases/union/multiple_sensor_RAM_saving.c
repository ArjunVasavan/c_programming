// Union allocates memory for only the largest member,
// enabling a single buffer slot to represent multiple sensor types —
// eliminating redundant memory on RAM-constrained MCUs (2KB–64KB)

#include <stdio.h>
#include <stdint.h>

typedef enum { TEMP, IMU, PRESSURE } SensorType_t;

typedef union {
    float    temperature;
    struct { float x, y, z; } imu;
    uint32_t pressure_pa;
} SensorData_t;

typedef struct {
    SensorType_t type;
    SensorData_t data;
} Sensor_t;

int main() {
    Sensor_t s;

    s.type             = TEMP;
    s.data.temperature = 36.5f;
    printf("Temp : %.2f C\n", s.data.temperature);

    s.type       = IMU;
    s.data.imu.x = 0.12f;
    s.data.imu.y = -0.45f;
    s.data.imu.z = 9.81f;
    printf("IMU  : X=%.2f Y=%.2f Z=%.2f\n",
            s.data.imu.x, s.data.imu.y, s.data.imu.z);

    s.type             = PRESSURE;
    s.data.pressure_pa = 101325;
    printf("Pres : %u Pa\n", s.data.pressure_pa);

    printf("Size : %zu bytes\n", sizeof(SensorData_t));
}
// Output:
// Temp : 36.50 C
// IMU  : X=0.12 Y=-0.45 Z=9.81
// Pres : 101325 Pa
// Size : 12 bytes
