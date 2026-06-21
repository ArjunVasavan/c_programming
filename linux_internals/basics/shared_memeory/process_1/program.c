#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

typedef struct {
    char str[30];
    int done;  // Flag: 0 = not done, 1 = done
} shared_data;

void upper_case(char* str) {
    int i = 0;
    while (str[i]) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 32;
        }
        i++;
    }
}

int main(int argc, char** argv) {
    char str[30];
    printf("Enter the string: ");
    scanf("%[^\n]", str);
    
    upper_case(str);
    
    // Creating shared memory
    int shmid = shmget((key_t)1234, sizeof(shared_data), 0666 | IPC_CREAT);
    if (shmid == -1) {
        perror("shmget");
        return 1;
    }
    
    // Attach to shared memory
    shared_data* data = (shared_data*)shmat(shmid, NULL, 0);
    if (data == (shared_data*)-1) {
        perror("shmat");
        return 1;
    }
    
    // Copy data to shared memory and initialize flag
    strcpy(data->str, str);
    data->done = 0;  // Reader hasn't finished yet
    
    printf("Uppercase: %s\n", str);
    printf("Data written to shared memory. Waiting for reader...\n");
    
    // Wait for reader to set the done flag
    while (data->done == 0) {
        usleep(100000);  // Sleep for 100ms to avoid busy waiting
    }
    
    printf("Reader has finished. Cleaning up...\n");
    
    // Detach and remove shared memory
    shmdt(data);
    shmctl(shmid, IPC_RMID, NULL);
    
    return 0;
}
