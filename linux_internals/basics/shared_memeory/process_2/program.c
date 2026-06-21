#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <unistd.h>

typedef struct {
    char str[30];
    int done;
} shared_data;

void reverse(char* str) {
    int i = 0;
    int len = strlen(str) - 1;
    
    while (i < len) {
        str[i] ^= str[len];
        str[len] ^= str[i];
        str[i] ^= str[len];
        
        i++;
        len--;
    }
}

int main(int argc, char** argv) {
    // Access existing shared memory
    int shmid = shmget((key_t)1234, sizeof(shared_data), 0666);
    if (shmid == -1) {
        perror("shmget - Make sure writer program runs first");
        return 1;
    }
    
    // Attach to shared memory
    shared_data* data = (shared_data*)shmat(shmid, NULL, 0);
    if (data == (shared_data*)-1) {
        perror("shmat");
        return 1;
    }
    
    printf("Read from shared memory: %s\n", data->str);
    
    // Reverse the string
    reverse(data->str);
    
    printf("Reversed: %s\n", data->str);
    
    // Set flag to indicate completion
    data->done = 1;
    
    printf("Signaled writer that processing is complete.\n");
    
    // Detach from shared memory
    shmdt(data);
    
    return 0;
}
